#ifndef __READER_FACTORY_h__
#define __READER_FACTORY_h__

#include <iostream>

#include "TableReader.h"
#include "MYSQLTableReader.h"
#include "OracleReader.h"
#include "PostgresReader.h"
#include "SGBDType.h"

/**
 * @brief      describe all type of SQLReader are implemented
 *
 * @note       the last enum LAST must be at the end , it's a trick for for
 *
 * @author     mochiwa
 * @date       17-Dec-2018
 */
//enum ReaderType {MYSQL,ORACLE,LAST};


class ReaderFactory
{
public:

    /**
     * @brief      Gets the reader.
     *
     * @return     The reader.
     *
     * @author     mochiwa
     * @date       17-Dec-2018
     */
    static TableReader* getReader(SGBDType const type);
};

#endif