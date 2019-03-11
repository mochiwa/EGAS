#include "MYSQLTypeDetector.h"

using namespace std;

bool MYSQLTypeDetector::isString(Attribute const& attribute) const
{
    if(!attribute.getType().compare("Varchar"))
        return true;
    return false;
}


bool MYSQLTypeDetector::isText(Attribute const& attribute) const
{
    if(!attribute.getType().compare("Text"))
        return true;
    return false;
}

bool MYSQLTypeDetector::isInteger(Attribute const& attribute) const
{
    if(!attribute.getType().compare("Int"))
        return true;
    return false;
}


bool MYSQLTypeDetector::isDouble(Attribute const& attribute)  const
{
    if(!attribute.getType().compare("Double") || !attribute.getType().compare("Float"))
        return true;
    return false;
}

bool MYSQLTypeDetector::isBoolean(Attribute const& attribute)  const
{
    if(!attribute.getType().compare("Bool"))
        return true;
    return false;
}

bool MYSQLTypeDetector::isDate(Attribute const& attribute)  const
{
    if(!attribute.getType().compare("Date"))
        return true;
    return false;
}

bool MYSQLTypeDetector::isDateTime(Attribute const& attribute)  const
{
    if(!attribute.getType().compare("Datetime"))
        return true;
    return false;
}