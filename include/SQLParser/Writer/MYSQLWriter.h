#ifndef __MYSQL_WRITER_H__
#define __MYSQL_WRITER_H__

#include <iostream>
#include <cstring>

#include "SQLWriter.h"

class MYSQLWriter:public SQLWriter
{
public:
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
    
};

#endif