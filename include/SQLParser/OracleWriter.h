#ifndef __ORACLE_WRITER_H__
#define __ORACLE_WRITER_H__

#include <iostream>
#include <cstring>

#include "SQLWriter.h"


class OracleWriter:public SQLWriter
{
public:
    /**
     * @brief      Appends a date.
     *
     * @param      value  The value
     *
     * @note       append To_DATE(value,'YYYY-MM-DD'),
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
     * @note       append To_DATE(value,'YYYY-MM-DD hh:mi:ss PM'),
     *
     * @author     mochiwa
     * @date       02-Jan-2019
     */
    virtual void appendDateTime(std::string const& value);
};

#endif