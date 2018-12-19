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
    return true;

}

bool MYSQLTableReader::isFileContainsForeignKey()
{
    return true;
}