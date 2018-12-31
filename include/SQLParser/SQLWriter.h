#ifndef __SQL_WRITER_H__
#define __SQL_WRITER_H__
    
#include <iostream>
#include <fstream>
#include <vector>

#include "Attribute.h"

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
    std::string querry;

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
    ~SQLWriter();
    
    /**
     * @brief      insert the initial querry keyword
     *
     * @param      tableName  The table name
     *
     * @note       init the querry with INSERT INTO <tableName>
     *
     * @author     mochiwa
     * @date       26-Dec-2018
     */
    void initLine(std::string const& tableName);

    /**
     * @brief      Appends attributes that will generated .
     *
     * @param      attributes  The attributes
     *
     * @note       insert into the begining of querry " (att1,att2,...) VALUES( "
     *
     * @author     mochiwa
     * @date       26-Dec-2018
     */
    void appendAttributes(std::vector<Attribute> const& attributes);

    /**
     * @brief      Appends a value.
     *
     * @param      value  The value
     *
     * @note       Append the value as string to the querry : " 'value', "
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
     * @note       Append the value as integer to the querry : " value, "
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
     * @note       Append the value as double to the querry : " value, "
     *
     * @author     mochiwa
     * @date       28-Dec-2018
     */
    void appendValue(double value,unsigned int const precision=2);

    /**
     * @brief      Closes the querry.
     *
     * @note       append the end of the querry ");"
     *
     * @author     mochiwa
     * @date       26-Dec-2018
     */
    void closeQuerry();

    /**
     * @brief      Writes a querry.
     *
     * @note       write the querry into the file
     *
     * @author     mochiwa
     * @date       26-Dec-2018
     */
    void writeQuerry();

    /**
     * @brief      Writes a querry.
     *
     * @param      file  The file
     *
     * @note       write the querry into the file
     *
     * @author     mochiwa
     * @date       28-Dec-2018
     */
    void writeQuerry(std::string const& file);

    /**
     * @brief      Gets the querry.
     *
     * @return     The querry.
     *
     * @author     mochiwa
     * @date       26-Dec-2018
     */
    std::string const& getQuerry();
};
#endif 