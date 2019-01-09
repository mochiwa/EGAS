#ifndef __OWNER_H__
#define __OWNER_H__

#include <iostream>
#include <string>

#define LINUX

namespace own
{

/**
 * @brief      Determines if the string is a number.
 *
 * @param      str   The string
 *
 * @return     True if number, False otherwise.
 *
 * @author     mochiwa
 * @date       06-Jan-2019
 */
bool isNumber(std::string const& str);


/**
 * @fn         int readInteger()
 * @brief      Reads an integer.
 *
 * @param      cursor  The cursor
 *
 * @return     the integer or -1 if > high value of integer
 */
int readInteger(std::string const& cursor=">");

/**
 * @fn         double readDouble()
 * @brief      Reads a double.
 * 
 * @param      cursor  The cursor
 *
 * @return     return double or -1 if > high value of double
 */
double readDouble(std::string const& cursor=">");


/**
 * @fn         bool getBinaryAnswer(char const* output)
 * @brief      Gets a binary answer (true/false).
 *
 * @param      output  The output
 *
 * @return     true or false
 */
bool getBinaryAnswer(std::string const& output);

/**
 * @brief      Ask to press enter
 *
 * @param      str   The string
 *
 * @author     mochiwa
 * @date       28-Dec-2018
 */
void proceed(std::string const& str=">>");

}//end namespace

#endif
