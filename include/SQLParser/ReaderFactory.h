#ifndef __READER_FACTORY_h__
#define __READER_FACTORY_h__

#include <iostream>

#include "TableReader.h"
#include "MYSQLTableReader.h"

/**
 * @brief      describe all type of SQLReader are implemented
 *
 * @note       the last enum LAST must be at the end , it's a trick for for
 *
 * @author     mochiwa
 * @date       17-Dec-2018
 */
enum ReaderType {MYSQL,ORACLE,LAST};


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
    static TableReader* getReader(ReaderType type);
};


/**
 * @brief      Show elegant type in string
 *
 * @param      os      The operating system
 * @param[in]  reader  The reader
 *
 * @return     std::ostream
 *
 * @note       just a cast to enum to a string
 *
 * @author     mochiwa
 * @date       17-Dec-2018
 */
std::ostream& operator<<(std::ostream& os,ReaderType reader);

#endif