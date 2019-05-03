#ifndef __POSTGRES_WRITER_H__
#define __POSTGRES_WRITER_H__

#include <iostream>
#include <cstring>

#include "SQLWriter.h"

class PostgresWriter:public SQLWriter
{
public:

    /**
     * @brief      writer the header of the file
     *
     * @author     mochiwa
     * @date       15-Jan-2019
     */
    virtual void initFile();

    /**
     * @brief      write comment with the table name into the file
     *
     * @param[in]  tableName  The table name
     * @param[in]  lines      The lines
     *
     * @author     mochiwa
     * @date       15-Jan-2019
     */
    virtual void initTable(std::string tableName,unsigned int lines);
    
    /**
     * @brief      Appends attributes.
     *
     * @param      attributes  The attributes
     *
     * @author     mochiwa
     * @date       15-Jan-2019
     */
    virtual void appendAttributes(std::vector<Attribute> const& attributes);
    /**
     * @brief      Appends a date.
     *
     * @param      value  The value
     *
     * @note       append STR_TO_DATE('value','%Y-%m-%d')
     *
     * @author     mochiwa
     * @date       02-Jan-2019
     */
    virtual void appendDate(std::string const& value);

    /**
     * @brief      Appends a date time.
     *
     * @param      value  The value
     *
     * @note       append STR_TO_DATE('value','%Y-%m-%d %H:%i:%s %p' )
     *
     * @author     mochiwa
     * @date       02-Jan-2019
     */
    virtual void appendDateTime(std::string const& value);


    /**
     * @brief      format a word to escape special character
     *
     * @param      string  The string
     *
     * @return     the formated word
     *
     * @author     mochiwa
     * @date       07-Jan-2019
     */
    virtual std::string formatedWord(std::string const& word);
    
    virtual void writeDrop(std::string const& tableName);

};

#endif