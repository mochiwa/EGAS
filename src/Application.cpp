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
    writer=nullptr;
    typeDetector=nullptr;

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

void Application::swapTable(int posA,int posB)
{
    Table tmp=tables.at(posA);

    tables.at(posA)=tables.at(posB);
    tables.at(posB)=tmp;
}

int Application::ArrangeForeignTable(int current,map<string,string> const& foreignKeys)
{
    unsigned int target;

    for(target=current+1; target<tables.size();++target)
        for(auto const& ref:foreignKeys)
            if(!tables[target].getName().compare(ref.second))
            {
                swapTable(current,target);
                return 0;
            }
    return current;
}

void Application::sortTable()
{
    unsigned int pos=0;
    unsigned int i=0;

    //placement of every table without foreignkey at first position
    for(i=0;i<tables.size();++i)
        if(tables.at(i).getForeignKeys().size()==0)
            swapTable(i,pos++);

    //Looking for tables that have foreign keys  
    for(;pos<tables.size();pos++)
        pos=ArrangeForeignTable(pos,tables[pos].getForeignKeys());     
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
    sortTable();
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

SGBDType Application::selectSQLType() const
{
    unsigned int selected=SGBDType::LAST;

    while(selected>=SGBDType::LAST)
    {
        CLEAR()
        showTitle("SQL SELECTION");

        for(int i=0;i<SGBDType::LAST;i++)
            cout<<i+1<<") "<<static_cast<SGBDType>(i)<<endl;
        selected=readInteger("Select: ")-1;
    }

    return static_cast<SGBDType>(selected);
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
    if(typeDetector->isInteger(att))
        writer->appendValue(clever.getInt());
    else if(typeDetector->isDouble(att))
        writer->appendValue(clever.getDouble());
    else if(typeDetector->isBoolean(att))
        writer->appendValue(clever.getBoolean());
    else if(typeDetector->isDate(att))
        writer->appendDate(clever.getDate());
    else if(typeDetector->isDateTime(att))
        writer->appendDateTime(clever.getDateTime());
    else if(typeDetector->isText(att))
        writer->appendValue("a long text that needs imagination to grow ...");//change
    else
        writer->appendValue(clever.getCleverValue(att.getName()));//change
}

void Application::automaticGeneration(Table const& table,int id)
{
    writer->initLine(table.getName());
    writer->appendAttributes(table.getAttributes());

    for(Attribute const& att:table.getAttributes())
    {
        if(att.getKeyType()==KeyType::primary)
            writer->appendValue(id);
        else if(att.getKeyType()==KeyType::foreign)
            writer->appendValue(id);//to change
        else if(att.getKeyType()==KeyType::both) 
            writer->appendValue(id);
        else
            cleverGeneration(att);
    }

    writer->closeQuerry();
    writer->writeQuerry(outputdir.getName()+"/SQLFILE.sql");
}

//TODO separer le code
void Application::generateLines()
{
    int maxLinesGenerate=0;
    int randomLines=0;

    CLEAR()
    showTitle("Lines generation");

   
    cout<<"Maximal line will generate: ";
    maxLinesGenerate=readInteger("");

    for(Table const& table:tables)
    {
        if(table.hasBothKey())
            randomLines=tablereferences.at(table.getReference(table.getPrimaryKey()->getName()));
        else
            randomLines=clever.getInt(1,maxLinesGenerate);

        randomLines=getTinyReference(table,randomLines);

        appendTableReference(table.getName(),randomLines-1);
        for(int line=0;line<randomLines;line++)
            automaticGeneration(table,line);
    }
}

void Application::appendTableReference(std::string const& table,int count)
{
    tablereferences.insert(reference(table,count));
}

int Application::getTinyReference(Table const& table,unsigned int baseValue) const
{
    int count=baseValue;

    if(!table.getForeignKeys().size())
        return count;

    for(auto const& v:table.getForeignKeys())
        if(tablereferences.at(v.second)<count)
            count=tablereferences.at(v.second);

    return count;
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

    sgbd=selectSQLType();
    reader=ReaderFactory::getReader(sgbd);
    typeDetector=TypeDetectorFactory::getDetector(sgbd);
        
    loadTables();

    writer=WriterFactory::getWriter(sgbd);

    generateLines();

    tmpdir.eraseContent();

    delete reader;
    delete writer;
}