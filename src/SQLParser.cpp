#include "SQLParser.h"

using namespace std;


SQLParser::SQLParser()
{
	setFilename("");
}

SQLParser::SQLParser(string const& name)
{
	setFilename(name);
	openFile();
}

SQLParser::~SQLParser()
{
	if(file.is_open())
		file.close();
}

//*******************************************************
//*******************  PRIVATE   ************************
//*******************************************************

string SQLParser::getSequence()
{
	char c=0;
	string word="";
    try
    {
        while(c!=';')
        {
            file.get(c);
            if(c==' ' || c==0 || c=='\n' || c=='\0' || c=='\t')
                return word;
            else
                word+=c;
        }
    }
    catch(ifstream::failure e)
    {
        return END_FILE;
    }
	return END_TABLE;
}

//*******************************************************
//******************  PROTECTED  ************************
//*******************************************************

void SQLParser::rewind()
{
	file.clear();
	file.seekg(0);
}

int SQLParser::getCursorPos()
{
	return file.tellg();
}

void SQLParser::setCursorAt(int pos)
{
	file.seekg(pos);
}

void SQLParser::removeChar(string& word,char const c)
{
	string tmp="";
	for(unsigned int i=0;i<word.size();++i)
		if(word[i]!=c)
			tmp+=word[i];
	word=tmp;
}

void  SQLParser::removeSequence(std::string& word,char const begin,char const end)
{
    string tmp="";
    unsigned int i;

    for(i=0;i<word.size() && word[i]!=begin;++i)
        tmp+=word[i];
    for(;i<word.size() && word[i]!=end;++i)
        continue;
    for(i++;i<word.size();++i)
        tmp+=word[i];

    word=tmp;
}

string SQLParser::readWordUntil(string const& sequence)
{
	string word="";
	string tmp="";

	while(tmp.compare(sequence) && tmp.compare(END_FILE) && tmp.compare(END_TABLE) )
	{
		word+=tmp;
		tmp=readWord();
	}

    if(!tmp.compare(END_FILE) || !tmp.compare(END_TABLE))
        return "";
    else
	   return word;
}

string SQLParser::readWord()
{
	string word="";
	while( word.compare(END_TABLE) && (!word.compare(" ") || !word.compare("")))
		word=getSequence();
	return word;
}


//*******************************************************
//********************  PUBLIC  *************************
//*******************************************************

void SQLParser::openFile()
{
	try
	{
		file.exceptions ( ifstream::badbit| ifstream::failbit);
		if(file.is_open())
			file.close();
		file.open(filename);
	}catch(ifstream::failure& e)
	{
		cout<<"Exception during opening the file: "+filename<<endl;
	}
}

//Todo : check if file exist before open ?
void SQLParser::openFile(string const& name)
{
	setFilename(name);
	openFile();
}

void SQLParser::closeFile()
{
	if(file.is_open())
		file.close();
}

string SQLParser::getTableToString()
{
    string table="";
    string key_create="";
    string key_table="";
    char c=0;

    while(key_create.compare(END_FILE) && key_create.compare(BEGIN_TABLE))
        key_create=readWord();

    key_table=readWord();
    if(key_table.compare("TABLE"))
        return END_FILE;

    table=key_create+" "+key_table+" ";

    while(c!=';')
    {
        file.get(c);
        table+=c;
    }

    return table;
}

vector<string> SQLParser::getTablesToString()
{
    string table="";
    vector<string> tables;
    rewind();
    for(table=getTableToString();table.compare(END_FILE);table=getTableToString())
        tables.push_back(table);
    return tables;
}

string SQLParser::toString() const
{
	string str="Parser :\n\t";
	
    str=+"FileName: "+filename;
	if(file.is_open())
		str+=" Open !";
	else
		str+=" Close !";
	return str;
}

//*******************************************************
//***************  GETTER AND SETTER  *******************
//*******************************************************

string const& SQLParser::getFilename() const
{
	return filename;
}

void SQLParser::setFilename(string const& name)
{
	this->filename=name;
}

//*******************************************************
//****************  EXTERN OPERATOR  ********************
//*******************************************************

ostream& operator<<(ostream& stream,SQLParser const& parser)
{
	stream << parser.toString();
	return stream;
}



