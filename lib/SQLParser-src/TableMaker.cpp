#include "TableMaker.h"

using namespace std;

TableMaker::TableMaker()
{

}

TableMaker::TableMaker(TableReader* reader)
{
	this->reader=reader;
}

TableMaker::~TableMaker()
{
	//todo
}

//*******************************************************
//*******************  PRIVATE  *************************
//*******************************************************
void TableMaker::setAttributes(Table& table)
{
	string word="";
	std::vector<Attribute> attributes;


	while((word=reader->getNextAttribute())!="" && word!=END_FILE)
		attributes.push_back(Attribute(word));
    
    
	for(unsigned int i=0;i<attributes.size();++i)
		setTypeOfAttribute(attributes[i]);

	table.setAttributes(attributes);
}

void TableMaker::setTypeOfAttribute(Attribute& attribute)
{
	string word="";
	word=reader->getType(attribute.getName());
	attribute.setType(word);
}
//*******************************************************
//********************  STATIC  *************************
//*******************************************************
Table TableMaker::getTable(TableReader* reader)
{
	TableMaker maker(reader);

	Table table=maker.getTable();
	return table;
}
//*******************************************************
//********************  PUBLIC  *************************
//*******************************************************
int TableMaker::countAttributes()
{
	int i=0;
	for(i=0;reader->getNextAttribute()!="";++i){}
	return i;
}

Table TableMaker::getTable()
{
	Table table(reader->getTableName());

	setAttributes(table);
	return table;
}
//*******************************************************
//***************  GETTER AND SETTER  *******************
//********************************************************

void TableMaker::setReader(TableReader *reader)
{
    this->reader=reader;
}