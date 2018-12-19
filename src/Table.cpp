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

int Table::getCountAttributes() const
{
	return attributes.size();
}

// TODO : ADD TRY/CATCH
Attribute const& Table::getAttribute(string const& name)
{
	unsigned int i;
	for(i=0;i<attributes.size();++i)
		if(attributes[i].getName()==name)
			return attributes[i];
	throw "NOT_FOUND"; 

}
// TODO : ADD TRY/CATCH
Attribute const& Table::getAttribute(unsigned int position)
{
	if(position>=0 && position<attributes.size())
		return attributes[position];
	else
		throw "BAD_INDEX";
}

string Table::toString() const
{
	unsigned int i;
	string str="Table("+to_string(id)+"):\n";
	str+=" Name: "+getName();
	str+=" Have "+to_string(attributes.size())+" Attributes\n";
	for(i=0;i<attributes.size();i++)
		str+="    "+attributes[i].toString()+"\n";
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