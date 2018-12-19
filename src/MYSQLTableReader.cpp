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
	while(word!="TABLE")
		word=readWord();
	word=readWord();
	removeChar(word,'(');
	return word;
}

string MYSQLTableReader::getNextAttribute()
{
	string word="";
	word=readWord();
	if(word==END_TABLE)
	{
		rewind();
		return "";
	}
	readWordUntil(",");
	return word;
}

string MYSQLTableReader::getType(std::string const& attribute)
{
	string word="";
	rewind();

	if(attribute=="")
		return "";

	while(word!=attribute)
		word=readWord();

	word=readWord();
	return word;
}

bool MYSQLTableReader::isFileContainsPrimaryKey()
{
    string word="";
    rewind(); 

    word=readWordUntil("PRIMARY");
    if(word!="")
        return true;
    return false;
}

bool MYSQLTableReader::isFileContainsForeignKey()
{
    string word="";
    rewind();

    word=readWordUntil("FOREIGN");
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

std::string MYSQLTableReader::getForeignKey()
{
    string word;
    
    word=readWordUntil("FOREIGN");
    if(word=="")
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