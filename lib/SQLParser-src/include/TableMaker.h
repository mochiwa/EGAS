#ifndef __TABLEMAKER_h__
#define __TABLEMAKER_h__

#include <iostream>
#include <cstring>
#include "SQLParser.h"
#include "TableReader.h"
#include "Table.h"
#include "Attribute.h"


/**
 * @brief      Class for table maker.
 *
 * @note        Generate Table object by reading sql file
 *
 * @author     mochiwa
 * @date       09-Dec-2018
 */
class TableMaker
{
private:
	TableReader* reader; /**< Parser responsible to read the file*/

    /**
     * @brief      Sets the attributes.
     *
     * @param      table  The table
     *
     * @note       Read the SQL file with the reader an make all attribute with their type
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	void setAttributes(Table& table);

    /**
     * @brief      Sets the type of attribute.
     *
     * @param      attribute  The attribute
     * 
     * @note       Read the SQL file with the reader an join all attribute to its type
     * 
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	void setTypeOfAttribute(Attribute& attribute);

public:
	
	

    /**
     * @brief      Constructs the object.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	TableMaker();

    /**
     * @brief      Constructs the object.
     *
     * @param      reader  The reader
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	TableMaker(TableReader* reader);

	/**
     * @brief      Destroys the object.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	~TableMaker();
//*******************************************************
//********************  STATIC  *************************
//*******************************************************

    /**
     * @brief      Gets the table.
     *
     * @param      reader  The reader
     *
     * @return     The table.
     *
     * @note       Provide a direct way to get a \p Table from a \p TableReader
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	static Table getTable(TableReader* reader);
//*******************************************************
//********************  PUBLIC  *************************
//*******************************************************

    /**
     * @brief      Counts the number of attributes.
     *
     * @return     Number of attributes.
     *
     * @note       Run through the file to seek how many attribute the file has
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	int countAttributes();

	/**
	 * @fn         Table getTable()
	 * @brief      Gets the table.
	 *
	 * @return     The table.
	 * 
	 * 
	 * 
	 * 
	 */

    /**
     * @brief      Gets the table.
     *
     * @return     The table.
     *
     * @note       step: 
     *                - 1) Make a table an found its name
     *                - 2) make attributes & type and append to table
     *                - 3) return the table
     * 
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	Table getTable();

//*******************************************************
//***************  GETTER AND SETTER  *******************
//*******************************************************

    /**
     * @brief      Sets the reader.
     *
     * @param      reader  The reader
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
    void setReader(TableReader *reader);
};


#endif