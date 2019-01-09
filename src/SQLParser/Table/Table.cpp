#include "Table.h"

using namespace std;
unsigned int Table::counter=0;
unsigned int Table::lastId=0;

Table::Table()
{
	init();
}

Table::Table(string const& name)
{
	init();
	setName(name);
}

Table::Table(Table const& src)
{
    init();
    setId(src.getId());
    setName(src.getName());
    setAttributes(src.getAttributes());
    setForeignKeys(src.getForeignKeys());
}

Table::~Table()
{
	counter--;
}

void Table::init()
{
	setId(lastId++);
	setName("");
	counter++;
}
//*******************************************************
//********************  STATIC  *************************
//*******************************************************

unsigned int Table::getCounter()
{
	return counter;
}

//*******************************************************
//********************  PUBLIC  *************************
//*******************************************************
void Table::appendAttribute(Attribute const& attribute)
{
	attributes.push_back(attribute);
}

void Table::appendForeignKey(string const& key,string const& table)
{
    foreignKeys.insert(foreignKey(key,table)); 
    for(Attribute & att:attributes )
        if(!att.getName().compare(key))
        {
            if(att.getKeyType()==KeyType::primary)
                att.setKeyType(KeyType::both);
            else
                att.setKeyType(KeyType::foreign);
        }
}

bool Table::hasForeignKey(std::string const& key) const
{
    if(foreignKeys.find(key)==foreignKeys.end())
        return false;
    return true;
}

bool Table::hasBothKey() const
{
    for(Attribute const& att:attributes)
        if(att.getKeyType()==KeyType::both)
            return true; 
    return false;
}

string const& Table::getReference(string const& foreignkey) const
{
    return foreignKeys.at(foreignkey);
}

int Table::getCountAttributes() const
{
	return attributes.size();
}

Attribute const& Table::getAttribute(string const& name) const
{
    for(Attribute const& att:attributes)
    {
        if(!att.getName().compare(name))
            return att;
    }
	throw "NOT_FOUND"; 
}

Attribute const& Table::getAttribute(unsigned int index) const
{
	return attributes.at(index);
}

string Table::toString() const
{
	string str="Table("+to_string(id)+"):\n";
	str+=" Name: "+getName();
	str+=" Have "+to_string(attributes.size())+" Attributes\n";
    for(Attribute const& att:attributes)
    {
        str+="    "+att.toString()+"\n";
    }
	return str;
}

//*******************************************************
//***************  GETTER AND SETTER  *******************
//*******************************************************

unsigned int Table::getId() const
{
    return id;
}

string const& Table::getName() const
{
	return name;
}

vector<Attribute> const& Table::getAttributes() const
{
	return attributes;
}

Attribute const* Table::getPrimaryKey() const
{
    for(Attribute const& att:attributes)
        if(att==KeyType::primary || att==KeyType::both)
            return &att;
    return nullptr;
}

map<string,string> const& Table::getForeignKeys() const
{
    return foreignKeys;
}

void Table::setId(unsigned int const id)
{
    this->id=id;
}

void Table::setName(string const& name)
{
	this->name=name;
}

void Table::setAttributes(vector<Attribute> attributes)
{
	this->attributes=attributes;
}

void Table::setPrimaryKey(std::string  const& attribute)
{
    for(Attribute & att:attributes)
    {
        if(!att.getName().compare(attribute))
            att.setKeyType(KeyType::primary);
        else if(att==KeyType::primary)
            att.setKeyType(KeyType::other);
    }
}

void Table::setForeignKeys(map<string,string> const& foreignKeys)
{
    this->foreignKeys=foreignKeys;
}
