/**
 * @file SQLParser.h
 * @brief Header of a Attribute class
 *
 * @date Nov 13, 2018
 * @author mochiwa
 */

#ifndef __Attribute_H__
#define __Attribute_H__

#include <iostream>
#include <cstring>

/**
 * @brief      Class for attribute.
 *
 * @note       This class describe an attribute in a SQLFile
 *
 * @author     mochiwa
 * @date       09-Dec-2018
 */
class Attribute
{
private:
	static unsigned int counter;/**< count the number of Attribute is alive.*/
    static unsigned int lastId;/**< the last id will be attributed.*/

	unsigned int id;/**< The unique ID.*/
	std::string name; /**< The name of the attribute.*/
	std::string type; /**< The type of the attribute.*/


    /**
     * @brief      initialize variables of the Attribute
     *
     * @note       used by all constructor to initialize variables of the Attribute.
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
    Attribute();

	/**
     * @brief      Constructs the object.
     *
     * @param      name  The name
     * @param      type  The type
     *
     * @note       Constructor with name and type, the default value of type is "".
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	Attribute(std::string const& name,std::string const& type="");

	/**
     * @brief      Destroys the object.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	~Attribute();
//*******************************************************
//********************  STATIC  *************************
//*******************************************************
    
    /**
     * @brief      Gets the counter.
     *
     * @return     The counter.
     *
     * @note       return how mutch Attribute is alive
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
    static unsigned int getCounter();
//*******************************************************
//********************  PUBLIC  *************************
//*******************************************************
	
    /**
     * @brief      Returns a string representation of the object.
     *
     * @return     String representation of the object.
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	std::string toString() const;
	
//------------------ OPERATORS ----------------------/
	
    /**
     * @brief      make a copy except ID
     *
     * @param      src   The source
     *
     * @return     attribute copied
     *
     * @note       copy attribute in src to the object
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	Attribute const& operator=(Attribute const& src);
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
     * @brief      Gets the type.
     *
     * @return     The type.
     *
     * @note       { paragraph }
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	std::string const& getType() const;

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
     * @brief      Sets the type.
     *
     * @param      type  The type
     *
     * @author     mochiwa
     * @date       09-Dec-2018
     */
	void setType(std::string const& type);
};




#endif