#include "MYSQLTableReader.h"

using namespace std;


MYSQLTableReader::MYSQLTableReader():TableReader(){}

MYSQLTableReader::MYSQLTableReader(std::string const& filename):TableReader(filename){}
MYSQLTableReader::~MYSQLTableReader(){}


//*******************************************************
//********************  STATIC  *************************
//*******************************************************


//*******************************************************
//********************  PUBLIC  *************************
//*******************************************************


string MYSQLTableReader::getTableName()
{
	string word="";
	rewind();

	while(word.compare("TABLE"))
		word=readWord();
	word=readWord();
	removeChar(word,'(');

	return word;
}

string MYSQLTableReader::getNextAttribute()
{
	string word="";

	word=readWord();
	if(!word.compare(END_TABLE))
		return "";
	readWordUntil(",");

	return word;
}

string MYSQLTableReader::getType(std::string const& attribute)
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

bool MYSQLTableReader::hasPrimaryKey()
{
    string word="";
    rewind(); 

    word=readWordUntil("PRIMARY");

    if(word!="")
        return true;
    return false;
}

bool MYSQLTableReader::hasForeignKey()
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

std::string  MYSQLTableReader::getPrimaryKey()
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

std::string MYSQLTableReader::getNextForeignKey()
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

std::string MYSQLTableReader::getForeignKeyReference()
{
    string word="";
    
    readWord();
    word=readWord();
    removeSequence(word,'(',')');

    return word;
}

/*
std::string MYSQLTableReader::getForeignKeyReference(std::string  const& key)
{
    string word="";
    string tmp="("+key+")";
    rewind();

    readWordUntil(tmp);
    return getForeignKeyReference();
}
*/