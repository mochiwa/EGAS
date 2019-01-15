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

    /**
     * @brief      Sets the primary key table.
     *
     * @param      table  The table
     *
     * @note       { paragraph }
     *
     * @author     mochiwa
     * @date       19-Dec-2018
     */
    void setPrimaryKeyTable(Table &table);

    /**
     * @brief      Sets the foreign keys.
     *
     * @param      table  The table
     *
     * @author     mochiwa
     * @date       21-Dec-2018
     */
    void setForeignKeys(Table &table);

    /**
     * @brief      Determines if type table.
     *
     * @return     True if type table, False otherwise.
     *
     * @note       if the name table contain type_ or Type_ or TYPE_
     *
     * @author     mochiwa
     * @date       14-Jan-2019
     */
    bool isTypeTable(Table const& table) const;

    /**
     * @brief      Determines if relation table.
     *
     * @return     True if relation table, False otherwise.
     *
     * @note       if the table doesn't have primary ou both key
     *
     * @author     mochiwa
     * @date       14-Jan-2019
     */
    bool isRelationTable(Table const& table) const;
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



/**
 * 
 * Probleme possible avec les tables qui hérite d'une autre table,
 * ex( pere-> fils) le fils a la meme id (au sens de table) que le pere
 * l'id fils est donc a la fois primay et foreign 
 * 
 */
