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
 * @fn         char readSingleChar()
 * @brief      Reads a single character.
 *
 * @param      cursor  The cursor
 *
 * @return     the char
 */
char readSingleChar(char const* cursor=">");

/**
 * @fn         int readInteger()
 * @brief      Reads an integer.
 *
 * @param      cursor  The cursor
 *
 * @return     the integer or -1 if > high value of integer
 */
int readInteger(char const* cursor=">");

/**
 * @fn         double readDouble()
 * @brief      Reads a double.
 * 
 * @param      cursor  The cursor
 *
 * @return     return double or -1 if > high value of double
 */
double readDouble(char const* cursor=">");

/**
 * @fn         bool getBinaryAnswer(char const* output)
 * @brief      Gets a binary answer (true/false).
 *
 * @param      output  The output
 *
 * @return     true or false
 */
bool getBinaryAnswer(char const* output);

/**
 * @fn         void resetChar(char *str,int size)
 * @brief      reset a char row.
 *
 * @param      char* the row
 * @param	   int size (last \0 not include)
 *
 */
void resetChar(char *str,int size);


void clearBuffer();
#endif