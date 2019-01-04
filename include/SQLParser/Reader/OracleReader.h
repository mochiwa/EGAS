#ifndef __ORACLE_READER_H__
#define __ORACLE_READER_H__

#include <iostream>
#include <cstring>

#include "TableReader.h"


/**
 * @brief      Class for oracle table reader.
 *
 * @note       A table reader for Oracle SGBD file
 *
 * @author     mochiwa
 * @date       09-Dec-2018
 */
class OracleReader:public TableReader
{
public:
    /**
     * @brief      Constructs the object.
     *
     * @author     mochiwa
     * @date       02-Jan-2019
     */
    OracleReader();

    /**
     * @brief      Constructs the object.
     *
     * @param      filename  The filename
     *
     * @author     mochiwa
     * @date       02-Jan-2019
     */
    OracleReader(std::string const& filename);

    /**
     * @brief      Destroys the object.
     *
     * @author     mochiwa
     * @date       02-Jan-2019
     */
    virtual ~OracleReader();
    

//*******************************************************
//********************  PUBLIC  *************************
//*******************************************************

    /**
     * @brief      Gets the table name.
     *
     * @return     The table name.
     *
     * @note       Put the cursor at the beginning, run through the file to find
     *             the name juste after the keyword TABLE and return it without
     *             '('
     * @see        readWord()
     * @see        removeChar()
     * 
     * @author     mochiwa
     * @date       09-Dec-2018
     */
    virtual std::string getTableName();

    /**
     * @brief      Gets the next attribute.
     *
     * @return     The next attribute or "" if END_TABLE was met.
     *
     * @note       get the first word after cursor and place the cursor just
     *             after the first ',' met .
     * @see        readWord()
     * @see        readWordUntil()
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
    virtual std::string getNextAttribute();

    /**
     * @brief      Gets the type.
     *
     * @param      attribute  The attribute
     * 
     * @return     The type.
     *
     * @note       rewind the file and looking for the attribute provided in
     *             parameter through the file, if it's found then return the
     *             next word.
     * @see        readWord()
     * @see        rewind()
     * 
     * @author     mochiwa
     * @date       09-Dec-2018
     */
    virtual std::string getType(std::string const& attribute);

    /**
     * @brief      Gets the atttribute size.
     *
     * @return     The atttribute size.
     *
     * @note        return the attribute size , or 0 if haven't
     *
     * @author     mochiwa
     * @date       04-Jan-2019
     */
    virtual unsigned int getAtttributeSize();

    /**
     * @brief      Determines if file contains primary key.
     *
     * @return     True if file contains primary key, False otherwise.
     *
     * @note       this function rewind the file before , not after
     *
     * @author     mochiwa
     * @date       19-Dec-2018
     */
    virtual bool hasPrimaryKey();

    /**
     * @brief      Determines if file contains foreign key.
     *
     * @return     True if file contains foreign key, False otherwise.
     *
     * @note       don't move the cursor
     *
     * @author     mochiwa
     * @date       19-Dec-2018
     */
    virtual bool hasForeignKey();

    /**
     * @brief      Gets the primary key.
     *
     * @return     The primary key.
     * @note       this function rewind the file before
     *
     * @author     mochiwa
     * @date       19-Dec-2018
     */
    virtual std::string getPrimaryKey();

    /**
     * @brief      Gets the first next foreign key.
     *
     * @return     The foreign key or "".
     *
     * @note       this fonction doesn't rewind the file! get the next
     *              foreign key if exist else return ""
     *
     * @author     mochiwa
     * @date       19-Dec-2018
     */
    virtual std::string getNextForeignKey();

    /**
     * @brief      Gets the foreign key reference.
     *
     * @return     The foreign key reference.
     *
     * @note       not rewind the file ! it must be call just after getForeignKey()
     * @see        getForeignKey()
     * 
     * @author     mochiwa
     * @date       19-Dec-2018
     */
    virtual std::string getForeignKeyReference();    
};

#endif