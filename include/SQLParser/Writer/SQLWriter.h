#ifndef __SQL_WRITER_H__
#define __SQL_WRITER_H__
    
#include <iostream>
#include <fstream>
#include <vector>

#include "Attribute.h"


#define RESERVED_CHAR {'\'','"',',','&','?','{','}','\\','(',')', \
                        '[',']','-',';','~','|','$','!','>','*', \
                        '%','_'}

/**
 * @brief      Class for sql writer.
 *
 * @note       How that work :
 *              1)Launch the SQLWriter::initLine(table name)    --> INSERT INTO xxx(
 *              2)SQLWriter::appendAttribute(vector attributes) --> att1,att2) VALUES(
 *              3)SQLWriter::appendValue(value)                 --> value1,value2, 
 *              4)SQLWriter::closeQuerry()                      --> );
 *              5)SQLWriter::writeQuerry()  
 *
 * @author     mochiwa
 * @date       28-Dec-2018
 */
class SQLWriter
{
private:
    std::ofstream file;
    std::string filename;

    /**
     * @brief      Opens a file.
     *
     * @throws     ifstream::failure badbit or  failbit (file can't open)
     * @note       check if the file is already open (then close) and try to open it 
     *             in fstream::out mode if file don't exist or app if file exists .
     *
     * @author     mochiwa
     * @date       26-Dec-2018
     */
    void openFile();

    /**
     * @brief      Closes a file.
     *
     * @note        if file is open then close it.
     *
     * @author     mochiwa
     * @date       26-Dec-2018
     */
    void closeFile();

    /**
     * @brief      Determines if file exist.
     *
     * @return     True if file exist, False otherwise.
     *
     * @author     mochiwa
     * @date       26-Dec-2018
     */
    bool isFileExist();

    /**
     * @brief      Sets the pricision of a double value.
     *
     * @param      value      The value
     * @param[in]  precision  The precision
     *
     * @return     the new double in a string
     *
     * @author     mochiwa
     * @date       31-Dec-2018
     */
    std::string setPricision(std::string const& value,unsigned int const precision);

protected:
    std::string query;

public:
    
    /**
     * @brief      Constructs the object.
     *
     * @note       The file where write will have a random name 
     *
     * @author     mochiwa
     * @date       26-Dec-2018
     */
    SQLWriter();

    /**
     * @brief      Constructs the object.
     *
     * @param      filename  The file name
     *
     * @author     mochiwa
     * @date       26-Dec-2018
     */
    SQLWriter(std::string const& filename);

    /**
     * @brief      Destroys the object.
     *
     * @author     mochiwa
     * @date       26-Dec-2018
     */
    virtual ~SQLWriter();

    /**
     * @brief      writer the header of the file
     *
     * @author     mochiwa
     * @date       15-Jan-2019
     */
    virtual void initFile()=0;
    
    /**
     * @brief      insert the initial query keyword
     *
     * @param      tableName  The table name
     *
     * @note       init the query with INSERT INTO <tableName>
     *
     * @author     mochiwa
     * @date       26-Dec-2018
     */
    void initLine(std::string const& tableName);

    /**
     * @brief      write comment with the table name into the file
     *
     * @param[in]  tableName  The table name
     * @param[in]  lines      The lines
     *
     * @author     mochiwa
     * @date       15-Jan-2019
     */
    virtual void initTable(std::string tableName,unsigned int lines)=0;

    /**
     * @brief      Appends attributes that will generated .
     *
     * @param      attributes  The attributes
     *
     * @note       insert into the begining of query " (att1,att2,...) VALUES( "
     *
     * @author     mochiwa
     * @date       26-Dec-2018
     */
    virtual void appendAttributes(std::vector<Attribute> const& attributes)=0;

    /**
     * @brief      Appends a value.
     *
     * @param      value  The value
     *
     * @note       Append the value as string to the query : " 'value', "
     *
     * @author     mochiwa
     * @date       26-Dec-2018
     */
    void appendValue(std::string const& value);

    /**
     * @brief      Appends a value.
     *
     * @param[in]  value  The value
     *
     * @note       Append the value as integer to the query : " value, "
     *
     * @author     mochiwa
     * @date       26-Dec-2018
     */
    void appendValue(int value);

    /**
     * @brief      Appends a value.
     *
     * @param[in]  value      The value
     * @param[in]  pricision  The pricision after the time
     *
     * @note       Append the value as double to the query : " value, "
     *
     * @author     mochiwa
     * @date       28-Dec-2018
     */
    void appendValue(double value,unsigned int const precision=2);

    /**
     * @brief      Appends a date.
     *
     * @param      value  The value
     *
     * @note       Append the date with the correct format of the SGBD
     *
     * @author     mochiwa
     * @date       02-Jan-2019
     */
    virtual void appendDate(std::string const& value)=0;

    /**
     * @brief      Appends a date time.
     *
     * @param      value  The value
     *
     * @note       Append the date with the correct format of the SGBD
     *
     * @author     mochiwa
     * @date       02-Jan-2019
     */
    virtual void appendDateTime(std::string const& value)=0;

    /**
     * @brief      format a word to escape special character
     *
     * @param      string  The string
     *
     * @return    the formated word
     *
     * @author     mochiwa
     * @date       07-Jan-2019
     */
    virtual std::string formatedWord(std::string const& word)=0;

    /**
     * @brief      Closes the query.
     *
     * @note       append the end of the query ");"
     *
     * @author     mochiwa
     * @date       26-Dec-2018
     */
    void closeQuerry();

    /**
     * @brief      Writes a query.
     *
     * @note       write the query into the file
     *
     * @author     mochiwa
     * @date       26-Dec-2018
     */
    void writeQuerry();

    /**
     * @brief      Writes a query.
     *
     * @param      file  The file
     *
     * @note       write the query into the file
     *
     * @author     mochiwa
     * @date       28-Dec-2018
     */
    void writeQuerry(std::string const& file);

    /**
     * @brief      Gets the query.
     *
     * @return     The query.
     *
     * @author     mochiwa
     * @date       26-Dec-2018
     */
    std::string const& getQuerry() const;

    /**
     * @brief      Sets the file name.
     *
     * @param      filename  The filename
     *
     * @author     mochiwa
     * @date       15-Jan-2019
     */
    void setFileName(std::string const& filename);
};
#endif 