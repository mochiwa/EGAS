/**
 * @file SQLParser.h
 * @brief Parser for SQL File
 *
 * @date Nov 9, 2018
 * @author mochiwa
 */

#ifndef __SQLPARSER_H__
#define __SQLPARSER_H__

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

#define BEGIN_TABLE "CREATE" /**< describe the first element that begin a table*/
#define END_TABLE ";"  /**< describe the last element that ending a table*/
#define END_FILE "EOF"  /**< when the file is finish*/

/**
 * @brief      Class for sql parser.
 *
 * @note       The purpose of this class, is:
 *              - give some simple functions able to read or write: word, keyword, type, name in a sql file.
 *              - Make a first structure of a SQLFile in String to work efficiency for programmer.
 *
 * @author     mochiwa
 * @date       09-Dec-2018
 */
class SQLParser
{
private:
	std::string filename; /**< The name/path of the file */
	std::ifstream file; /**< The handle for file */

    /**
     * @brief      Gets the sequence.
     *
     * @return     The buffer before sequence. Or END_TABLE.
     *
     * @note       Read the file until \a ';' or \a sequence of char was found.
     *             A sequence means a set of char without \c [' ',0,'\n','\0','\t'].
     *             
     * @throws     ifstream::failure if the file is finished , return END_FILE              
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	std::string getSequence();

protected:
	
	/**
     * @brief      Gets the cursor position.
     *
     * @return     The cursor position.
     *
     * @note       Gets the cursor position in the file.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	int getCursorPos();

	/**
     * @brief      Sets the cursor at.
     *
     * @param[in]  pos   The position
     *
     * @note       move the cursor in file at the position.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	void setCursorAt(int pos);

    /**
     * @brief      put the cursor at the beginning
     *
     * @note       move the cursor at the beginning of the file 
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
    void rewind();

    /**
     * @brief      Removes a character.
     *
     * @param      word  The word where remove the character
     * @param      c     the character to remove   
     *
     * @note       Remove all characters occur in the word
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	void removeChar(std::string& word,char const c) const;

    /**
     * @brief      Removes a sequence.
     *
     * @param      word   The word
     * @param[in]  begin  The begin character where cut
     * @param[in]  end    The end character where cut
     *
     * @note       Remove everything beetween char begin and end
     *
     * @author     mochiwa
     * @date       19-Dec-2018
     */
    void removeSequence(std::string& word,char const begin,char const end) const;


    /**
     * @brief      Reads a word until.
     *
     * @param      sequence  The sequence
     *
     * @return     all words before the sequence without it
     *
     * @note       Run through the file until the \a sequence was found.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	 std::string readWordUntil(std::string const& sequence);

    /**
     * @brief      Reads a word.
     *
     * @return     a word without space
     *
     * @note       A word mean a sequence of char[0 to inf] between two [' ', 0 , \n , '\0', '\t'].
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
    std::string readWord();

public:
    
	/**
     * @brief      Constructs the object.
     *
     * @note       The default constructor.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	SQLParser();

    /**
     * @brief      Constructs the object.
     *
     * @param      filename  The name of the file
     *
     * @note       Construct with a filename and open the file directly.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	SQLParser(std::string const& filename);

	/**
     * @brief      Destroys the object.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	virtual ~SQLParser();

//*******************************************************
//********************  PUBLIC  *************************
//*******************************************************

	/**
     * @brief      Opens a file.
     *
     * @throws     ifstream::failure badbit or  failbit (file can't open)
     * @note       check if the file is already open (then close) and try to open it.
     * 
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	void openFile();

    /**
     * @brief      Opens a file.
     *
     * @param      filename  The name of the file
     *
     * @note       set the filename name and open the file.
     * @see        openFile()
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	void openFile(std::string const& filename);

	/**
     * @brief      Closes a file.
     *
     * @note       if file is open then close it.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	void closeFile();

    /**
     * @brief      Gets the table to string.
     *
     * @return     The table to string.
     *
     * @note       Run through the word \a BEGIN_TABLE in the file and begins
     *             the reading until the character END_TABLE or END_FILE was found,
     *             put every thing between in a string to return.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
    std::string getTableToString();

    /**
     * @fn         getTablesToString()
     * @brief      Gets all tables in the file
     *
     * @return     vector within all table in string
     */

    /**
     * @brief      Gets tables to string.
     *
     * @return     A vector of string within all table
     *
     * @note       Read whole file and make a vector of string within all tables read in the file
     * @see        getTableToString();
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
    std::vector<std::string> getTablesToString();

    /**
     * @brief      Returns a string representation of the object.
     *
     * @return     String representation of the object.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	std::string toString() const;

//*******************************************************
//***************  GETTER AND SETTER  *******************
//*******************************************************

    /**
     * @brief      Gets the filename.
     *
     * @return     The filename.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	std::string const& getFilename() const;

    /**
     * @brief      Sets the filename.
     *
     * @param      name  The name
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	void setFilename(std::string const& name);


};

/**
 * @brief      Overloading of << toString
 *
 * @param      stream  The stream
 * @param      parser  The parser
 *
 * @return     ostream 
 *
 * @note       just call SQLParser::toString() and print
 *
 * @author     mochiwa
 * @date       09-Dec-2018
 */
std::ostream& operator<<(std::ostream& stream,SQLParser const& parser);

#endif


/**
 * @todo: find a solution for compare string and char in a elegant way
 */
