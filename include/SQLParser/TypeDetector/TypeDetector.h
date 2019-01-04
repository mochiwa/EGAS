#ifndef __TYPE_DETECTOR_H__
#define __TYPE_DETECTOR_H__

#include <iostream>
#include <cstring>

#include "Attribute.h"

enum Type_attribute
{
    STRING,
    TEXT,
    INTEGER,
    DOUBLE,
    BOOLEAN,
    DATE,
    DATETIME,

};


class TypeDetector
{
public:
    TypeDetector();
    virtual ~TypeDetector();
    
    /**
     * @brief      Determines if the attribute is a string.
     *
     * @return     True if string, False otherwise.
     *
     * @author     mochiwa
     * @date       04-Jan-2019
     */
    virtual bool isString(Attribute const& attribute) const=0;

    /**
     * @brief      Determines if the attribute is a text.
     *
     * @param      attribute  The attribute
     *
     * @return     True if text, False otherwise.
     *
     * @author     mochiwa
     * @date       04-Jan-2019
     */
    virtual bool isText(Attribute const& attribute) const=0;

    /**
     * @brief      Determines if the attribute is an integer.
     *
     * @param      attribute  The attribute
     *
     * @return     True if integer, False otherwise.
     *
     * @author     mochiwa
     * @date       04-Jan-2019
     */
    virtual bool isInteger(Attribute const& attribute) const=0;

    /**
     * @brief      Determines if the attribute is a double.
     *
     * @param      attribute  The attribute
     *
     * @return     True if double, False otherwise.
     *
     * @author     mochiwa
     * @date       04-Jan-2019
     */
    virtual bool isDouble(Attribute const& attribute) const=0;

    /**
     * @brief      Determines if the attribute is a boolean.
     *
     * @param      attribute  The attribute
     *
     * @return     True if boolean, False otherwise.
     *
     * @author     mochiwa
     * @date       04-Jan-2019
     */
    virtual bool isBoolean(Attribute const& attribute) const=0;

    /**
     * @brief      Determines if the attribute is a date.
     *
     * @param      attribute  The attribute
     *
     * @return     True if date, False otherwise.
     *
     * @author     mochiwa
     * @date       04-Jan-2019
     */
    virtual bool isDate(Attribute const& attribute) const=0;

    /**
     * @brief      Determines if the attribute is a datetime.
     *
     * @param      attribute  The attribute
     *
     * @return     True if date time, False otherwise.
     *
     * @author     mochiwa
     * @date       04-Jan-2019
     */
    virtual bool isDateTime(Attribute const& attribute) const=0;
};

#endif


/**
 
    bool isString(Attribute const& attribute)
    {

    }


    bool isText(Attribute const& attribute)
    {

    }

    bool isInteger(Attribute const& attribute)
    {

    }


    bool isDouble(Attribute const& attribute) 
    {

    }

    bool isBoolean(Attribute const& attribute) 
    {

    }

    bool isDate(Attribute const& attribute) 
    {

    }

    bool isDateTime(Attribute const& attribute) 
    {

    }


 */
