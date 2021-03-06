#ifndef __MYSQL_TYPE_H__
#define __MYSQL_TYPE_H__

#include <iostream>
#include <cstring>
#include "TypeDetector.h"

class MYSQLTypeDetector: public TypeDetector
{
public:
    /**
     * @brief      Determines if the attribute is a string.
     *
     * @return     True if string, False otherwise.
     *
     * @author     mochiwa
     * @date       04-Jan-2019
     */
    bool isString(Attribute const& attribute) const ;

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
    bool isText(Attribute const& attribute) const ;

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
    bool isInteger(Attribute const& attribute) const ;

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
    bool isDouble(Attribute const& attribute) const ;

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
    bool isBoolean(Attribute const& attribute) const ;

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
    bool isDate(Attribute const& attribute) const ;

    /**
     * @brief      Determines if the attribute is a datetime.
     *
     * @param      attribute  The attribute
     *
     * @return     True if datetime, False otherwise.
     *
     * @author     mochiwa
     * @date       04-Jan-2019
     */
    bool isDateTime(Attribute const& attribute) const ;
};

#endif