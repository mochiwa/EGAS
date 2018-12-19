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
	string tpm="";
	for(unsigned int i=0;i<word.size();++i)
		if(word[i]!=c)
			tpm+=word[i];
	word=tpm;
}

string SQLParser::readWordUntil(string const& sequence)
{
	string word="";
	string tpm="";
	while(tpm != sequence && tpm!=END_FILE && tpm!=END_TABLE )
	{
		word+=tpm;
		tpm=readWord();
	}
    if(tpm==END_FILE || tpm==END_TABLE)
        return "";
    else
	   return word;
}

string SQLParser::readWord()
{
	string word="";
	while( word!=END_TABLE && (word==" " || word==""))
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

    for(key_create="";key_create!=END_FILE && key_create!=BEGIN_TABLE;key_create=readWord()){}

    key_table=readWord();
    if(key_table!="TABLE")
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
    for(table=getTableToString();table!=END_FILE;table=getTableToString())
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



