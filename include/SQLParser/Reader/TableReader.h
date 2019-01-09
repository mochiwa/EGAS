#ifndef __TABLEREADER_H__
#define __TABLEREADER_H__

#include <iostream>
#include <cstring>
#include "SQLParser.h"

/**
 * @brief      Abstract class for table reader.
 *
 * @note       This class is an abstract class that each table reader must be
 *             inherited to provide the basic function to fill an \p Table.
 *
 * @author     mochiwa
 * @date       09-Dec-2018
 */
class TableReader : public SQLParser
{
private:

public:

    
    /**
     * @brief      Constructs the object.
     *
     * @note       The default constructor.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
    TableReader();

    /**
     * @brief      Constructs the object with a filename.
     *
     * @param[in]  filename  The filename
     *
     * @note       call the constructor of @p SQLParser
     * @see        SQLParser::SQLParser(std::string const& filename)
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
    TableReader(std::string const& filename);

    /**
     * @brief      Destroys the object.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	virtual ~TableReader();

    /**
     * @brief      Gets the att size.
     *
     * @return     The att size.
     *
     * @note       Provide a way to search the size of the attribute
     *
     * @author     mochiwa
     * @date       04-Jan-2019
     */
    virtual unsigned int getAtttributeSize()=0;

    /**
     * @brief      Gets the table name.
     *
     * @return     The table name.
     *
     * @note       Provide the way to find the table name in a file
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
    virtual std::string getTableName()=0;

    /**
     * @brief      Gets the next attribute.
     *
     * @return     The next attribute.
     *
     * @note       Provide a way to find the next(about cursor pos)  attribute
     *             in the file
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
    virtual std::string getNextAttribute()=0;

    /**
     * @brief      Gets the type.
     *
     * @param      attribute  The attribute
     *
     * @return     The type.
     *
     * @note       Provide a way to find the type of the attribute provided in
     *             parameter
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
    virtual std::string getType(std::string const& attribute)=0;

    /**
     * @brief      Determines if file contains primary key.
     *
     * @return     True if file contains primary key, False otherwise.
     *
     * @author     mochiwa
     * @date       19-Dec-2018
     */
    virtual bool hasPrimaryKey()=0;

    /**
     * @brief      Determines if file contains foreign key.
     *
     * @return     True if file contains foreign key, False otherwise.
     *
     * @author     mochiwa
     * @date       19-Dec-2018
     */
    virtual bool hasForeignKey()=0;

    /**
     * @brief      Gets the primary key.
     *
     * @return     The primary key.
     *
     * @author     mochiwa
     * @date       19-Dec-2018
     */
    virtual std::string getPrimaryKey()=0;

    /**
     * @brief      Gets the foreign key.
     *
     * @return     The foreign key.
     *
     * @author     mochiwa
     * @date       19-Dec-2018
     */
    virtual std::string getNextForeignKey()=0;

    /**
     * @brief      Gets the foreign key reference.
     *
     * @return     The foreign key reference.
     *
     * @author     mochiwa
     * @date       19-Dec-2018
     */
    virtual std::string getForeignKeyReference()=0;
};

#endif