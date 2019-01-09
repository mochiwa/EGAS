#include "OracleTypeDetector.h"

using namespace std;

bool OracleTypeDetector::isString(Attribute const& attribute) const
{
    if(!attribute.getType().compare("VARCHAR2"))
        return true;
    return false;
}


bool OracleTypeDetector::isText(Attribute const& attribute) const
{
    if(!attribute.getType().compare("CLOB"))
        return true;
    return false;
}

bool OracleTypeDetector::isInteger(Attribute const& attribute) const
{
    if(!attribute.getType().compare("NUMBER") && !isBoolean(attribute))
        return true;
    return false;
}


bool OracleTypeDetector::isDouble(Attribute const& attribute) const
{
    if(!attribute.getType().compare("FLOAT"))
        return true;
    return false;
}

bool OracleTypeDetector::isBoolean(Attribute const& attribute) const
{
    if(!attribute.getType().compare("NUMBER") && attribute.getSize()==1)
        return true;
    return false;
}

bool OracleTypeDetector::isDate(Attribute const& attribute) const
{
    if(!attribute.getType().compare("DATE"))
        return false;
    return false;
}

bool OracleTypeDetector::isDateTime(Attribute const& attribute) const
{
    if(!attribute.getType().compare("DATE"))
        return true;
    return false;
}