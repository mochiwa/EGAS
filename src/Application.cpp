#include "Application.h"

using namespace std;

Application::Application()
{
    init();
}

Application::~Application()
{

}

//*******************************************************
//*******************  PRIVATE  *************************
//*******************************************************
void Application::init()
{   
    reader=nullptr;

    inputdir=Directory("input");
    tmpdir=Directory("tmp");
    outputdir=Directory("output");
    library=Directory("library");

    inputdir.read();
    tmpdir.read();
    outputdir.read();
    library.read();
}

void Application::showTitle(string const& str) const
{
    unsigned int i;
    unsigned int lineUp;
    unsigned int lineDown;

    if(str.length()%2==0)
        lineUp=lineDown=43;
    else
        lineUp=lineDown=42;
    for(i=0;i<lineUp;++i)
        cout<<"#";

    cout<<endl<<"##";
    lineUp-=2;
    for(i=0;i<((lineUp-str.length())/2);++i)
        cout<<" ";

    cout<<str;

    lineUp-=3;
    for(i=0;i<((lineUp-str.length())/2);++i)
        cout<<" ";
    cout<<"##"<<endl;

    for(i=0;i<lineDown;++i)
        cout<<"#";
    cout<<endl;
}

void Application::tmpdirManagement()
{   
    CLEAR()
    showTitle("TMP DIR MANAGEMENT");
    cout<<"The tmp dir must be empty and it contens "<<tmpdir.getCountFile()<<" files :"<<endl;
    tmpdir.printFiles();
    cout<<"please move files or delete their "<<endl;

    if(!getBinaryAnswer("delete files ?"))
    {
        cout<<"Please move files before to press Return...";
        cin.get();
    }
    else
        tmpdir.eraseContent();
    tmpdir.read();
}

void Application::sliceSQLFile(string const& filepath)
{
    SQLParser parser(filepath);
    vector<string> tables;
    ofstream outfile;
    int i=0;

    tables=parser.getTablesToString();
    for(string const& table:tables)
    {
        outfile=ofstream((tmpdir.getDirName()+"/SQL-"+to_string(i++)));
        outfile<<table;
        outfile.close();
    }
    tmpdir.read();
}

void Application::loadTables()
{
    for(string file:tmpdir.getFiles())
    {
        file=tmpdir.getFilePath(file);
        reader->openFile(file);
        tables.push_back(TableMaker::getTable(reader));
        reader->closeFile();
    }
}

std::string Application::selectInputFile()
{
    unsigned selected=-1;
    do
    {
        CLEAR()
        showTitle("INPUT DIR FILE SELECTION");
        if(inputdir.isEmpty())
        {
            cout<<"Your input directory is empty, insert files into and press Return"<<endl;
            cin.get();
            inputdir.read();
        }
        else
        {
            inputdir.printFiles();
            selected=readInteger("Select: ")-1;
        }
    }while(selected>=inputdir.getCountFile());

    return inputdir.getFilePath(selected);
}

//TODO def one begin and one last readerType
ReaderType Application::selectSQLType() const
{
    unsigned int selected=ReaderType::LAST;

    while(selected>=ReaderType::LAST)
    {
        CLEAR()
        showTitle("SQL SELECTION");
        for(int i=0;i<ReaderType::LAST;i++)
            cout<<i+1<<") "<<static_cast<ReaderType>(i);
        selected=readInteger("Select: ")-1;
    }

    return static_cast<ReaderType>(selected);
}

Table const& Application::selectTable() const
{
    unsigned int selected=0;
    unsigned int i=1;

    do
    {
        CLEAR()
        showTitle("SELECT A TABLE");
        for(Table const& table:this->tables)
            cout<<i++<<") "<<table.getName()<<endl;
        selected=readInteger("Select: ")-1;
    }while(selected>tables.size());

    return tables[selected];
}

//*******************************************************
//********************  PUBLIC  *************************
//*******************************************************


void Application::run()
{
    string sqlFile="";

    showTitle("EGAS");

    while(!sqlFile.compare(""))
        sqlFile=selectInputFile();

    while(!tmpdir.isEmpty())
        tmpdirManagement();

    sliceSQLFile(sqlFile);

    readerType=selectSQLType();
    reader=ReaderFactory::getReader(readerType);

    loadTables();


    Table table=selectTable();
    for(int i=0;i<100;i++)
    {
        writer.initLine(table.getName());

        writer.appendAttributes(table.getAttributes());

        for(Attribute const& att:table.getAttributes())
        {
            if(att.getKeyType()==KeyType::primary)
                writer.appendValue((int)att.getId());
            else if(att.getKeyType()==KeyType::foreign)
            {
                if(table.hasForeignKey(att.getName()))
                    writer.appendValue(table.getReference(att.getName()));
            }
            else
                writer.appendValue("A_RANDOM_VALUE"); //here
        }
        writer.closeQuerry();

        writer.writeQuerry(outputdir.getDirName()+"/"+table.getName());
    }
    tmpdir.eraseContent();
    delete reader;
}