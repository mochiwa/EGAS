#ifndef __OWNER_H__
#define __OWNER_H__

#include <iostream>
#include <string>  

#define LINUX
#ifdef LINUX
	#define CLEAR() system("clear");
#else
	#define CLEAR() system("cls");
#endif

/**
 * @brief      Reads a single character.
 *
 * @param      cursor  The cursor
 *
 * @return     the char
 *
 * @author     mochiwa
 * @date       28-Dec-2018
 */
char readSingleChar();

/**
 * @brief      Reads an integer.
 *
 * @param      cursor  The cursor
 *
 * @return     the integer or -1 if > high value of integer
 * @author     mochiwa
 * @date       28-Dec-2018
 */
int readInteger(char const* cursor=">");

/**
 * @brief      Reads a double.
 *
 * @param      cursor  The cursor
 *
 * @return     return double or -1 if > high value of double
 *
 * @author     mochiwa
 * @date       28-Dec-2018
 */
double readDouble(char const* cursor=">");

/**
 * @brief      Gets a binary answer (true/false).
 *
 * @param      output  The output
 *
 * @return     true or false
 *
 * @author     mochiwa
 * @date       28-Dec-2018
 */
bool getBinaryAnswer(char const* output);

/**
 * @fn         void resetChar(char *str,int size)
 *
 *
 * @brief      reset a char row.
 *
 * @param      str   The string
 * @param      char*  the row
 * @param      int    size (last \0 not include)
 *
 * @author     mochiwa
 * @date       28-Dec-2018
 */
void resetChar(char *str,int size);


/**
 * @brief      Ask to press enter
 *
 * @param      str   The string
 *
 * @author     mochiwa
 * @date       28-Dec-2018
 */
void proceed(char const* str=">>");
#endif