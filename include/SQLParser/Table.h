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
#include "Attribute.h"


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
	Attribute const& getAttribute(std::string const& name);

    /**
     * @brief      Gets the attribute.
     *
     * @param      position  The position
     *
     * @return     The attribute.
     * @throws     BAD_INDEX the position provided in parameter is less 0 or upper list size
     *
     * @note       Run through the list as far as the position provided in parameter
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	Attribute const& getAttribute(unsigned int position);


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

};
#endif