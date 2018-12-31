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
    cout<<"The tmp dir must be empty and it contends "<<tmpdir.getCountFile()<<" files :"<<endl;
    tmpdir.printFiles();
    cout<<"please move files or delete their "<<endl;

    if(!getBinaryAnswer("delete files ?"))
    {
        cout<<"Please move files before to press Return..."<<endl;
        proceed();
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
        outfile=ofstream((tmpdir.getName()+"/SQL-"+to_string(i++)));
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

string Application::selectInputFile()
{
    unsigned int selected=-1;

    while(selected>=inputdir.getCountFile())
    {
        CLEAR()
        showTitle("INPUT DIR FILE SELECTION");
        inputdir.printFiles();
        if(inputdir.isEmpty())
        {
            cout<<"Your input directory is empty, insert files into and press Return"<<endl;
            proceed();
            inputdir.read();
        }
        else
            selected=readInteger("Select: ")-1;
    }

    return inputdir.getFilePath(selected);
}

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
    unsigned int selected=-1;
    unsigned int i=1;

    while(selected>tables.size())
    {
        CLEAR()
        showTitle("SELECT A TABLE");

        for(Table const& table:this->tables)
            cout<<i++<<") "<<table.getName()<<endl;
        selected=readInteger("Select: ")-1;
    }
    return tables[selected];
}

void Application::cleverGeneration(Attribute const& att)
{
    if(!att.getType().compare("Double"))
        writer.appendValue(rand() % 50);
    else if(!att.getType().compare("Int"))
        writer.appendValue(rand() % 10);
    else
        writer.appendValue("DATA");
}

void Application::automaticGeneration(Table const& table,int i)
{
    writer.initLine(table.getName());
    writer.appendAttributes(table.getAttributes());
    for(Attribute const& att:table.getAttributes())
    {
        if(att.getKeyType()==KeyType::primary)
            writer.appendValue(i);
        else if(att.getKeyType()==KeyType::foreign)
         writer.appendValue( rand() % tablereferences.at(table.getName()));
        else
            cleverGeneration(att);
    }
    writer.closeQuerry();
    writer.writeQuerry(outputdir.getName()+"/SQLFILE.sql");
}

//TODO separer le code
void Application::generateLines()
{
    int count=0;
    bool random=true;

    CLEAR()
    showTitle("Lines generation");
    cout<<"Maximal line will generate: ";
    count=readInteger("");

    srand(time(NULL));
    for(Table const table:tables)
    {
        appendTableReference(table.getName(),count);
        for(int i=0;i<count;i++)
        {
            automaticGeneration(table,i);
            
        }
    }
}

void Application::appendTableReference(std::string const& table,int count)
{
    tablereferences.insert(reference(table,count));
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

    reader=ReaderFactory::getReader(selectSQLType());

    loadTables();

    generateLines();

    tmpdir.eraseContent();
    delete reader;
}