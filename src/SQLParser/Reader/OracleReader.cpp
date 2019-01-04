#include "OracleReader.h"

using namespace std;

OracleReader::OracleReader():TableReader(){}

OracleReader::OracleReader(string const& filename):TableReader(filename){}

OracleReader::~OracleReader(){}

//*******************************************************
//********************  STATIC  *************************
//*******************************************************


//*******************************************************
//********************  PUBLIC  *************************
//*******************************************************

string OracleReader::getTableName()
{
    string word="";
    rewind();

    while(word.compare("TABLE"))
        word=readWord();
    word=readWord();
    removeChar(word,'(');

    return word;
}

string OracleReader::getNextAttribute()
{
    string word="";

    word=readWord();
    if(!word.compare("CONSTRAINT"))
        return "";
    readWordUntil(",");

    return word;
}

string OracleReader::getType(std::string const& attribute)
{
    string word="";
    rewind();

    if(!attribute.compare(""))
        return "";
    while(word.compare(attribute))
        word=readWord();
    word=readWord();
    return word;
}

unsigned int OracleReader::getAtttributeSize()
{
    string str=readWord();
    if(str[0]!='(')
        return 0;

    removeChar(str,'(');
    removeChar(str,')');
    return stoi(str);
}


bool OracleReader::hasPrimaryKey()
{
    string word="";
    rewind(); 

    word=readWordUntil("PRIMARY");

    if(word!="")
        return true;
    return false;
}

bool OracleReader::hasForeignKey()
{
    string word="";
    int pos=0;

    pos=getCursorPos();
    rewind();
    word=readWordUntil("FOREIGN");
    setCursorAt(pos);

    if(word!="")
        return true;
    return false;
}

std::string  OracleReader::getPrimaryKey()
{
    string word="";
    rewind();

    readWordUntil("PRIMARY");
    readWord();
    word=readWord();
    removeChar(word,'(');
    removeChar(word,')');

    return word;
}

std::string OracleReader::getNextForeignKey()
{
    string word="";
    
    word=readWordUntil("FOREIGN");
    if(!word.compare(""))
        return "";
    readWord();
    word=readWord();
    removeChar(word,'(');
    removeChar(word,')');

    return word;
}

std::string OracleReader::getForeignKeyReference()
{
    string word="";
    
    readWord();
    word=readWord();
    removeSequence(word,'(',')');

    return word;
}