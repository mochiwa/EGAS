#include "SQLWriter.h"


using namespace std;

SQLWriter::SQLWriter()
{
    filename="RandomName";//TODO
}
SQLWriter::SQLWriter(string const& filename)
{   
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
//*******************************************************
//********************  PUBLIC  *************************
//*******************************************************

void SQLWriter::initLine(string const& tableName)
{
    querry="INSERT INTO "+tableName+"(";
}

void SQLWriter::appendAttributes(vector<Attribute> const& attributes)
{
    for(Attribute const& att:attributes)
        querry+=att.getName()+",";
    querry.back()=')';
    querry+=" VALUES (";
}

void SQLWriter::appendValue(string const& value)
{
    querry+="'"+value+"',";
}

void SQLWriter::appendValue(int value)
{
    querry+=to_string(value)+",";
}

void SQLWriter::appendValue(double value)
{
    querry+=to_string(value)+",";
}

void SQLWriter::closeQuerry()
{
    querry.back()=')';
    querry+=";\n";
}

void SQLWriter::writeQuerry()
{
    openFile();
    file<<querry;
    closeFile();
}

void SQLWriter::writeQuerry(string const& filename)
{
    this->filename=filename;
    writeQuerry();
}

//*******************************************************
//***************  GETTER AND SETTER  *******************
//*******************************************************

string const& SQLWriter::getQuerry()
{
    return querry;
}