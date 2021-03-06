#include "Application.h"

using namespace std;
using namespace own;
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


void Application::showAttributeFiles(Table const& table)
{
    showTitle(("Table: "+table.getName()));
    for(Attribute const& att:table.getAttributes())
    {
        if(!typeDetector->isText(att) && !typeDetector->isString(att))
        {
            cout<<"# "<<att.getName()<<"...............";
            if(typeDetector->isInteger(att))
                cout<<"random_integer 0 to 100"<<endl;
            else if(typeDetector->isDouble(att))
                cout<<"random_double 0 to 100"<<endl;
            else if(typeDetector->isBoolean(att))
                cout<<"random_boolean 0 to 100"<<endl;
            else if(typeDetector->isDate(att))
                cout<<"random_date"<<endl;
            else if(typeDetector->isDateTime(att))
                cout<<"random_dateTime"<<endl;
        }
    }
    for(auto it=attributeFiles.begin(); it != attributeFiles.end();++it)
        cout<<"# "<<it->first->getName()<<"..............."<<it->second<<endl;
    cout<<"####################################"<<endl;
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
    Table::sortTable(tables);
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

string Application::selectLibraryFile()
{
    unsigned int selected=-1;

    while(selected>=library.getCountFile())
    {
        cout<<"0) ** Reload files ** "<<endl;
        library.printFiles();
        if(library.isEmpty())
        {
            cout<<"Your library directory is empty, insert files into and press Return"<<endl;
            proceed();
            library.read();
        }
        else
        {
            selected=readInteger("Select: ");
            if(selected==0)
                library.read();
            selected--;
        }
    }
    return library.getFilePath(selected);
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
    return tables.at(selected);
}

void Application::cleverGeneration(Attribute const& att)
{
    if(typeDetector->isInteger(att))
        writer->appendValue(clever.getInt());
    else if(typeDetector->isDouble(att))
        writer->appendValue(clever.getDouble());
    else if(typeDetector->isBoolean(att))
        if(sgbd==SGBDType::POSTGRES)
            writer->appendValue(to_string(clever.getBoolean()));
        else
            writer->appendValue(clever.getBoolean());
    else if(typeDetector->isDate(att))
        writer->appendDate(clever.getDate());
    else if(typeDetector->isDateTime(att))
        writer->appendDateTime(clever.getDateTime());
    else 
        writer->appendValue(WordGetter::getWord(attributeFiles.at(&att)));
}

bool operator==(uniqueRelation a,uniqueRelation b)
{
    if(a.first==b.first && a.second==b.second)
        return true;
    return false;
}

uniqueRelation Application::getUniqueRelation(Table const& table)
{
    int a;
    int b;
    uniqueRelation relation;
    string tableA=table.getAttributes()[0].getName();
    string tableB=table.getAttributes()[1].getName();
    do
    {
        a=clever.getRandomId(tableReferences.at(table.getReference(tableA)));
        b=clever.getRandomId(tableReferences.at(table.getReference(tableB)));
        relation.first=a;
        relation.second=b;
   }while(alreadyCreate(relation));

    uniqueRelations.push_back(relation);
    return relation;
}
void Application::existingGeneration(Attribute const& att)
{
    string data=WordGetter::getWord(attributeFiles.at(&att));
    try
    {
        if(typeDetector->isInteger(att))
            writer->appendValue(stoi(data));
        else if(typeDetector->isDouble(att))
            writer->appendValue(stod(data));
        else if(typeDetector->isBoolean(att))
        {
            if(sgbd!=SGBDType::POSTGRES)
                writer->appendValue(stoi(data));

        }
        else if(typeDetector->isDate(att))
            writer->appendDate(data);
        else if(typeDetector->isDateTime(att))
            writer->appendDateTime(data);
        else 
            writer->appendValue(data);
    }catch(invalid_argument e)
    {
        writer->appendValue(data);
    }
    catch(out_of_range e)
    {
      writer->appendValue(0);  
    }

}

bool Application::alreadyCreate(uniqueRelation r)
{
    for(auto const& relation:uniqueRelations)
        if(r==relation)
            return true;
    return false;
}

void Application::automaticGeneration(Table const& table,int id)
{
    uniqueRelation relation;
    writer->initLine(table.getName());
    writer->appendAttributes(table.getAttributes());

    if(table.getType()==TypeTable::RELATION)
    {
        relation=getUniqueRelation(table);
        writer->appendValue(relation.first);
        writer->appendValue(relation.second);
    }

    for(Attribute const& att:table.getAttributes())
    {
        if(att.getKeyType()==KeyType::primary)
            if(sgbd!=SGBDType::MYSQL && sgbd!=SGBDType::POSTGRES)
                writer->appendValue(id);
            else
                continue;
        else if(att.getKeyType()==KeyType::foreign && table.getType()!=TypeTable::RELATION)
            writer->appendValue(clever.getRandomId(tableReferences.at(table.getReference(att.getName()))));
        else if(att.getKeyType()==KeyType::both) 
            writer->appendValue(id);
        else
            if(table.getType()==TypeTable::TYPE)
                writer->appendValue(WordGetter::getWord(attributeFiles.at(&att),id));
            else if(hasAttribute(&att))
                 existingGeneration(att);
            else if(att.getKeyType()!=KeyType::foreign)
                cleverGeneration(att);
    }
    writer->closeQuerry();
    writer->writeQuerry();
}

//TODO separer le code
void Application::generateLines()
{
    int maxLinesGenerate=0;
    int lines=0;
    do
    {
        CLEAR()
        showTitle("Lines generation");
        cout<<"Maximal line will generate: ";
        maxLinesGenerate=readInteger("");
    }while(maxLinesGenerate <=2);
    
    for(Table const& table:tables)
    {
        if(table.getType()==TypeTable::TYPE && library.isFileExist(table.getName()))
        {
            initTypeTable(table);
        }
        else if(table.getType()==TypeTable::RELATION)
        {
            initRelationTable(table,maxLinesGenerate);
        }
        else
        {
            initTable(table,maxLinesGenerate);
        }
        lines=tableReferences.at(table.getName());
        writer->initTable(table.getName(),lines);

        for(int line=0;line<lines;line++)
            automaticGeneration(table,line);
        attributeFiles.clear();
        uniqueRelations.clear();
    }
}

void Application::appendTableReference(std::string const& table,int count)
{
    tableReferences.insert(reference(table,count));
}

void Application::appendAttributeFile(Attribute const& att,std::string const& file)
{
    attributeFiles.insert(att_file(&att,file));
}

void Application::fillAttributeFiles(Table const& table)
{
    for(Attribute const& att:table.getAttributes())
    {
        CLEAR();
        showAttributeFiles(table);

        if(library.isFileExist(att.getName()))
            appendAttributeFile(att,library.getFilePath(att.getName()));
        else if(typeDetector->isString(att) ||typeDetector->isText(att))
        {
            cout<<"Select a file for "+att.getName()<<":"<<endl;
            appendAttributeFile(att,selectLibraryFile());       
        }
    }
}

unsigned int Application::reduceRelationCount(unsigned int countLines,int max)
{
    double lines=pow(2,countLines);
    if(lines<(max*10)&&lines<pow(2,max))
        return (unsigned int)lines;
    return reduceRelationCount(countLines-1,max);
}

void Application::initTypeTable(Table const& table)
{
    int countLines=0;
    countLines=WordGetter::getMaxWord(library.getFilePath(table.getName()));
    for(Attribute const& att:table.getAttributes())
        if(typeDetector->isString(att))
            appendAttributeFile(att,library.getFilePath(table.getName()));
    appendTableReference(table.getName(),countLines);

}

void Application::initRelationTable(Table const& table,unsigned int maxLines)
{
    unsigned int countLines=0;
    unsigned int ref=0;
    for(auto const& att:table.getForeignKeys())
    {
        ref=tableReferences.at(att.second);
        if(ref>countLines)
            countLines=ref;
    }
    countLines=reduceRelationCount(countLines,maxLines);
    countLines=clever.getInt(1,countLines);
    appendTableReference(table.getName(),countLines);
}

void Application::initTable(Table const& table,unsigned int lines)
{
    unsigned int countLine=0;
    fillAttributeFiles(table);
    if(table.hasBothKey())
        countLine=tableReferences.at(table.getReference(table.getPrimaryKey()->getName()));//cas heritage
    else
        countLine=lines;
    appendTableReference(table.getName(),countLine);
}

bool Application::hasAttribute(Attribute const* att)
{
    for(auto const& data: attributeFiles)
        if(data.first==att)
            return true;
    return false;
}
//*******************************************************
//********************  PUBLIC  *************************
//*******************************************************


void Application::run()
{

    string sqlFile="";
    string sqlOutput="";

    showTitle("EGAS");

    while(!sqlFile.compare(""))
        sqlFile=selectInputFile();

    while(!tmpdir.isEmpty())
        tmpdirManagement();

    sliceSQLFile(sqlFile);

    sgbd=selectSQLType();
    reader=ReaderFactory::getReader(sgbd);
    typeDetector=TypeDetectorFactory::getDetector(sgbd);
    clever.setMinimalId(sgbd);
    loadTables();


    writer=WriterFactory::getWriter(sgbd);


    do
    {
        CLEAR();
        showTitle("Output Name");
        cout<<"Output name:";
        cin>>sqlOutput;
    }while(!sqlOutput.size());
    writer->setFileName((outputdir.getName()+"/"+sqlOutput));

    writer->initFile();


    for(auto t:tables)
        writer->writeDrop(t.getName());
    
    SQLParser parser(sqlFile);
    writer->copyFileInto(parser.getTablesToString());

    
    generateLines();
    
    
    tmpdir.eraseContent();

    delete typeDetector;
    delete reader;
    delete writer;
}