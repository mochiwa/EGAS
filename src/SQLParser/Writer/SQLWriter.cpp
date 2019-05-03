#include "SQLWriter.h"


using namespace std;

SQLWriter::SQLWriter()
{
    query="";
    filename="RandomName";//TODO
}
SQLWriter::SQLWriter(string const& filename)
{   
    query="";
    this->filename=filename;
}

SQLWriter::~SQLWriter()
{
    closeFile();
}

//*******************************************************
//*******************  PRIVATE   ************************
//*******************************************************

void SQLWriter::openFile()
{
    try
    {
        file.exceptions( ifstream::badbit| ifstream::failbit);
        if(file.is_open())
            file.close();
        if(isFileExist())
            file.open(filename,fstream::app);
        else
            file.open(filename,fstream::out);
    }catch(ifstream::failure& e)
    {
        cout<<"Exception during opening the file: "+filename<<endl;
    }
}

void SQLWriter::closeFile()
{
    if(file.is_open())
        file.close();
}


bool SQLWriter::isFileExist()
{
    bool value=false;
    ifstream f(filename);
    if(f.good())
        value=true;

    f.close();
    return value;
}


string SQLWriter::setPricision(string const& value,unsigned int const precision)
{
    string str="";
    unsigned int i=0;
    unsigned int max=0;

    while(value[i]!='.' &&  i<value.size())
        str+=value[i++];

    max=i+precision;
    for(;i<value.size() && i<max;++i)
        str+=value[i];
    return str;
}
//*******************************************************
//********************  PUBLIC  *************************
//*******************************************************

void SQLWriter::initLine(string const& tableName)
{
    query="INSERT INTO "+tableName+"(";
}

void SQLWriter::appendValue(string const& value)
{
    query+="'"+formatedWord(value)+"',";
}

void SQLWriter::appendValue(int value)
{
    query+=to_string(value)+",";
}

void SQLWriter::appendValue(double value,unsigned int const precision)
{
    query+=setPricision(to_string(value),precision)+",";
}

void SQLWriter::closeQuerry()
{
    query.back()=')';
    query+=";\n";
}

void SQLWriter::writeQuerry()
{
    openFile();
    file<<query;
    closeFile();
    query="";
}

void SQLWriter::writeQuerry(string const& filename)
{
    this->filename=filename;
    writeQuerry();
}

//*******************************************************
//***************  GETTER AND SETTER  *******************
//*******************************************************

string const& SQLWriter::getQuerry() const
{
    return query;
}

void SQLWriter::setFileName(string const& filename)
{
    this->filename=filename;
}

void SQLWriter::copyFileInto(std::vector<std::string> tables)
{
    for(string const& t:tables)
    {
        query+="\n------------------------------"+'\n';
        query+='\n'+t+'\n';
        query+="\n------------------------------"+'\n';
    }
    query+="\n\n\n\n";
    writeQuerry();
}