#include "Attribute.h"

using namespace std;

unsigned int Attribute::counter=0;
unsigned int Attribute::lastId=0;

Attribute::Attribute()
{
	init();
}

Attribute::Attribute(string const& name,string const& type)
{
	init();
	setName(name);
	setType(type);
}

Attribute::~Attribute()
{
	counter--;
}

//*******************************************************
//********************  PRIVATE  ************************  
//*******************************************************
void Attribute::init()
{
	setId(lastId++);
	setName("");
	setType("");
    setKeyType(other);
	counter++;
}
//*******************************************************
//********************  STATIC  *************************
//*******************************************************
unsigned int Attribute::getCounter()
{
	return counter;
}
//*******************************************************
//********************  PUBLIC  *************************
//*******************************************************
std::string Attribute::toString() const
{
	string str="Attribute("+to_string(id)+"):\n";
	str+="  Name: "+getName();
	str+="  Type: "+getType();
    str+="  KeyType: "+ keyTypeToString();
	return str;
}

std::string Attribute::keyTypeToString() const
{
    switch(keyType)
    {
        case primary:
            return "primary";
            break;
        case foreign:
            return "foreign";
            break;
        case other:
            return "None";
            break;
    }
    return "";
}

Attribute const& Attribute::operator=(Attribute const& src)
{
	setName(src.getName());
	setType(src.getType());
	return *this;
}

bool Attribute::operator==(KeyType keyType) const
{
    if(this->keyType==keyType)
        return true;
    return false;
}
//*******************************************************
//***************  GETTER AND SETTER  *******************
//*******************************************************
unsigned int Attribute::getId() const
{
    return id;
}

KeyType Attribute::getKeyType() const
{
    return keyType;
}

string const& Attribute::getName() const
{
	return name;
}

string const& Attribute::getType() const
{
	return type;
}

void Attribute::setId(unsigned int const id)
{
    this->id=id;
}

void Attribute::setKeyType(KeyType type)
{
    this->keyType=type;
}

void Attribute::setName(string const& name)
{
	this->name=name;
}

void Attribute::setType(string const& type)
{
	this->type=type;
}