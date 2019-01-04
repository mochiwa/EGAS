#include "MYSQLTypeDetector.h"

using namespace std;

bool MYSQLTypeDetector::isString(Attribute const& attribute)
{
    if(!attribute.getType().compare("Varchar"))
        return true;
    return false;
}


bool MYSQLTypeDetector::isText(Attribute const& attribute)
{
    if(!attribute.getType().compare("Text"))
        return true;
    return false;
}

bool MYSQLTypeDetector::isInteger(Attribute const& attribute)
{
    if(!attribute.getType().compare("Int"))
        return true;
    return false;
}


bool MYSQLTypeDetector::isDouble(Attribute const& attribute) 
{
    if(!attribute.getType().compare("Double"))
        return true;
    return false;
}

bool MYSQLTypeDetector::isBoolean(Attribute const& attribute) 
{
    if(!attribute.getType().compare("Bool"))
        return true;
    return false;
}

bool MYSQLTypeDetector::isDate(Attribute const& attribute) 
{
    if(!attribute.getType().compare("Date"))
        return false;
    return false;
}

bool MYSQLTypeDetector::isDateTime(Attribute const& attribute) 
{
    if(!attribute.getType().compare("Datetime"))
        return true;
    return false;
}