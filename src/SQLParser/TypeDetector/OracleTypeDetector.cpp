#include "OracleTypeDetector.h"

using namespace std;

bool OracleTypeDetector::isString(Attribute const& attribute)
{
    if(!attribute.getType().compare("VARCHAR2"))
        return true;
    return false;
}


bool OracleTypeDetector::isText(Attribute const& attribute)
{
    if(!attribute.getType().compare("CLOB"))
        return true;
    return false;
}

bool OracleTypeDetector::isInteger(Attribute const& attribute)
{
    if(!attribute.getType().compare("NUMBER"))
        return true;
    return false;
}


bool OracleTypeDetector::isDouble(Attribute const& attribute) 
{
    if(!attribute.getType().compare("FLOAT"))
        return true;
    return false;
}

bool OracleTypeDetector::isBoolean(Attribute const& attribute) 
{
    if(isInteger(attribute) && attribute.getSize()==1)
        return true;
    return false;
}

bool OracleTypeDetector::isDate(Attribute const& attribute) 
{
    if(!attribute.getType().compare("DATE"))
        return false;
    return false;
}

bool OracleTypeDetector::isDateTime(Attribute const& attribute) 
{
    if(!attribute.getType().compare("DATE"))
        return true;
    return false;
}