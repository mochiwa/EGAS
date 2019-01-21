#include "PostgresTypeDetector.h"


using namespace std;

bool PostgresTypeDetector::isString(Attribute const& attribute) const
{
    if(!attribute.getType().compare("VARCHAR"))
        return true;
    return false;
}


bool PostgresTypeDetector::isText(Attribute const& attribute) const
{
    if(!attribute.getType().compare("Text"))//////
        return true;
    return false;
}

bool PostgresTypeDetector::isInteger(Attribute const& attribute) const
{
    if(!attribute.getType().compare("INT") || !attribute.getType().compare("SERIAL") )
        return true;
    return false;
}


bool PostgresTypeDetector::isDouble(Attribute const& attribute)  const
{
    if(!attribute.getType().compare("FLOAT8")||!attribute.getType().compare("FLOAT"))
        return true;
    return false;
}

bool PostgresTypeDetector::isBoolean(Attribute const& attribute)  const
{
    if(!attribute.getType().compare("BOOL"))
        return true;
    return false;
}

bool PostgresTypeDetector::isDate(Attribute const& attribute)  const
{
    if(!attribute.getType().compare("DATE"))
        return true;
    return false;
}

bool PostgresTypeDetector::isDateTime(Attribute const& attribute)  const
{
    if(!attribute.getType().compare("Datetime"))
        return false;
    return false;
}