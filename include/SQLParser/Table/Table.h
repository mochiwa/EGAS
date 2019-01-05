/**
 * @file Table.h
 * @brief Header of a Table class
 *
 * @date Nov 13, 2018
 * @author mochiwa
 */

#ifndef __TABLE_H__
#define __TABLE_H__
#include <iostream>
#include <cstring>
#include <vector>
#include <map>

#include "Attribute.h"

typedef std::pair<std::string,std::string> foreignKey ;/** < This Typedef is a pair to append to the foreignkyes */

/**
 * @brief      Class for table.
 *
 * @note       This class describe an Table in a SQLFile.
 *
 * @author     mochiwa
 * @date       09-Dec-2018
 */
class Table
{
private:
	static unsigned int counter;/**< Count the number of Type is alive. */
    static unsigned int lastId;/**< The last id will be attributed. */

	unsigned int id;/**< The unique ID. */
	std::string name; /**< The name of the table. */
	std::vector<Attribute> attributes; /**< List of \p Attribute in the table. */

   // std::string primaryKey; /**< Primary key of the map */
    std::map<std::string, std::string> foreignKeys; /**< Map of foreign key  foreignKey - table*/

	/**
     * @brief      initialize variables of the Table
     *
     * @note       used by all constructor to initialize variables.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	void init();
public:

	/**
     * @brief      Constructs the object.
     *
     * @note       The default constructor.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	Table();

    /**
     * @brief      Constructs the object.
     *
     * @param      src   The source
     *
     * @author     mochiwa
     * @date       01-Jan-2019
     */
    Table(Table const& src);

	/**
     * @brief      Constructs the object.
     *
     * @param      name  The name
     *
     * @note       Construct with a name
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	Table(std::string const& name);

	/**
     * @brief      Destroys the object.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	~Table();
//*******************************************************
//********************  STATIC  *************************
//*******************************************************
    
    /**
     * @brief      Gets the counter.
     *
     * @return     The counter.
     *
     * @note       return how much Attribute is alive
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
    static unsigned int getCounter();

//*******************************************************
//********************  PUBLIC  *************************
//*******************************************************

	/**
     * @brief      Appends an attribute.
     *
     * @param      attribute  The attribute
     *
     * @note       Append an \p Attribute to the list of attributes.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	void appendAttribute(Attribute const& attribute);

    /**
     * @brief      Appends a foreign key.
     *
     * @param      key    The key
     * @param      value  The value
     *
     * @author     mochiwa
     * @date       19-Dec-2018
     */
    void appendForeignKey(std::string const& key,std::string const& table);

    /**
     * @brief      Determines if the key is a foreign key of the table.
     *
     * @param      key   The key
     *
     * @return     True if a is foreign key, False otherwise.
     *
     * @note       { paragraph }
     *
     * @author     mochiwa
     * @date       19-Dec-2018
     */
    bool hasForeignKey(std::string const& key) const;

    /**
     * @brief      Determines if it has both key.
     *
     * @return     True if has both key, False otherwise.
     *
     * @author     mochiwa
     * @date       05-Jan-2019
     */
    bool hasBothKey() const;

    /**
     * @brief      Gets the reference.
     *
     * @param[in]  key   The key
     *
     * @return     The table reference associated at the foreignkey .
     *
     * @author     mochiwa
     * @date       28-Dec-2018
     */
    std::string const& getReference(std::string const& foreignkey)const;

	/**
     * @brief      Gets the number of attributes alive.
     *
     * @return     The number of attributes alive.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	int getCountAttributes() const;

    /**
     * @brief      Gets the attribute.
     *
     * @param      name  The name
     *
     * @return     The attribute.
     * @throws     NOT_FOUND Attribute with \a name not found
     * @note       Run through the list to find an \p Attribute
     *             with the \a name provided in parameter.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	Attribute const& getAttribute(std::string const& name) const;

    /**
     * @brief      Gets the attribute.
     *
     * @param[in]  index  The index
     *
     * @return     The attribute.
     *
     * @note       Run through the list as far as the position provided in
     *             parameter
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	Attribute const& getAttribute(unsigned int index)const ;


	/**
     * @brief      Returns a string representation of the object.
     *
     * @return     String representation of the object.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	std::string toString() const;

//*******************************************************
//***************  GETTER AND SETTER  *******************
//*******************************************************
	
    /**
     * @brief      Gets the identifier.
     *
     * @return     The identifier.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
    unsigned int getId() const;

	/**
     * @brief      Gets the name.
     *
     * @return     The name.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	std::string const& getName() const;

	/**
     * @brief      Gets the attributes.
     *
     * @return     The attributes.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	std::vector<Attribute> const& getAttributes() const;

    /**
     * @brief      Gets the primary key.
     *
     * @return     The primary key.
     *
     * @author     mochiwa
     * @date       19-Dec-2018
     */
    Attribute const* getPrimaryKey() const;

    /**
     * @brief      Gets the foreign keys.
     *
     * @return     The foreign keys as a map 
     *
     * @author     mochiwa
     * @date       19-Dec-2018
     */
    std::map<std::string,std::string> const& getForeignKeys() const;

	/**
     * @brief      Sets the identifier.
     *
     * @param      id    The identifier
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
    void setId(unsigned int const id);

	/**
     * @brief      Sets the name.
     *
     * @param      name  The name
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	void setName(std::string const& name);

	/**
     * @brief      Sets the attributes.
     *
     * @param      attributes  The attributes
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
    void setAttributes(std::vector<Attribute> attributes);

    /**
     * @brief      Sets the primary key.
     *
     * @param      key   The key
     *
     * @note       set the primary key and try notify the attribute
     *
     * @author     mochiwa
     * @date       20-Dec-2018
     */
    void setPrimaryKey(std::string  const& attribute);

    /**
     * @brief      Sets the foreign keys.
     *
     * @param      foreignkeys  The foreignkeys
     *
     * @author     mochiwa
     * @date       01-Jan-2019
     */
    void setForeignKeys(std::map<std::string,std::string> const& foreignKeys);

};
#endif