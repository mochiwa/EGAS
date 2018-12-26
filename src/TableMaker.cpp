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
    
    for(Attribute & att:attributes)
		setTypeOfAttribute(att);

	table.setAttributes(attributes);
}

void TableMaker::setPrimaryKeyTable(Table &table)
{
    if(reader->hasPrimaryKey())
        table.setPrimaryKey(reader->getPrimaryKey());
}

void TableMaker::setForeignKeys(Table &table)
{
    string key="";
    string reference="";

    while((key=reader->getNextForeignKey())!="")
    {
        reference=reader->getForeignKeyReference();
        table.appendForeignKey(key,reference);
    }

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

Table TableMaker::getTable()
{
	Table table(reader->getTableName());

	setAttributes(table);
    setPrimaryKeyTable(table);

    if(reader->hasForeignKey())
    {
        setForeignKeys(table);
    }
    
	return table;
}
//*******************************************************
//***************  GETTER AND SETTER  *******************
//********************************************************

void TableMaker::setReader(TableReader *reader)
{
    this->reader=reader;
}