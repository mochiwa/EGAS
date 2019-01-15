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


	while((word=reader->getNextAttribute()).compare("") && word.compare(END_FILE))
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

    while((key=reader->getNextForeignKey()).compare(""))
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
    attribute.setSize(reader->getAtttributeSize());
}

bool TableMaker::isTypeTable(Table const& table) const
{
    string name=table.getName();
    if(name.find("Type_")!=string::npos || name.find("type_")!=string::npos || name.find("TYPE_")!=string::npos)
        if(!isRelationTable(table))
            return true;
    return false;
}

bool TableMaker::isRelationTable(Table const& table) const
{
    for(Attribute const& att:table.getAttributes())
        if(att.getKeyType()==KeyType::primary || att.getKeyType()==KeyType::both)
            return false;
    return true;
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
        setForeignKeys(table);

    if(isTypeTable(table))
    {
        table.setType(TypeTable::TYPE);
    }
    else if(isRelationTable(table))
    {
        table.setType(TypeTable::RELATION);
    }
    else
    {
        table.setType(TypeTable::NORMAL);
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