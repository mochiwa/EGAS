#include "PostgresReader.h"

using namespace std;


PostgresReader::PostgresReader():TableReader(){}

PostgresReader::PostgresReader(std::string const& filename):TableReader(filename){}
PostgresReader::~PostgresReader(){}


//*******************************************************
//********************  PUBLIC  *************************
//*******************************************************

string PostgresReader::getTableName()
{
    string word="";
    rewind();

    while(word.compare("TABLE"))
        word=readWord();
    word=readWord();
    removeChar(word,'(');
    removeSequence(word,'p','.');
    return word;
}

string PostgresReader::getNextAttribute()
{
    string word="";

    word=readWord();
    if(!word.compare(END_TABLE) || !word.compare("CONSTRAINT"))
        return "";

    readWordUntil(",");
    return word;
}

string PostgresReader::getType(std::string const& attribute)
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

unsigned int PostgresReader::getAtttributeSize()
{
    string str=readWord();
    if(str[0]!='(')
        return 0;

    removeChar(str,'(');
    removeChar(str,')');
    return stoi(str);
}


bool PostgresReader::hasPrimaryKey()
{
    string word="";
    rewind(); 

    word=readWordUntil("PRIMARY");

    if(word!="")
        return true;
    return false;
}

bool PostgresReader::hasForeignKey()
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

std::string  PostgresReader::getPrimaryKey()
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

std::string PostgresReader::getNextForeignKey()
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

std::string PostgresReader::getForeignKeyReference()
{
    string word="";
    
    readWord();
    word=readWord();
    removeSequence(word,'(',')');
    removeSequence(word,'p','.');

    return word;
}