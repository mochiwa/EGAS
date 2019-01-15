#ifndef __CLEVERGENERATOR_H__
#define __CLEVERGENERATOR_H__

#include <iostream>
#include <cstdlib>
#include <map>

#include "own_random.h"
#include "Directory.h"
#include "WordGetter.h"

#include "Table.h"
#include "Attribute.h"

typedef std::pair<int,int> uniqueRelation;

/**
 * @brief      The purpose of this class is to give random data
 *
 * @author     mochiwa
 * @date       10-Jan-2019
 */
class CleverGenerator
{
private:
    own_random generator; /** < the number generator */
    //WordGetter wordGetter; /** < the file manager */
   // Directory *library; /** < Directory where take file*/

    //std::map<Table const*,int> lineMax; /** < table and count line max will generated*/
    //std::map<Attribute const*,std::string> attFiles; /** < attribute and file where take */

public:

    /**
     * @brief      Constructs the object.
     *
   
     * @author     mochiwa
     * @date       31-Dec-2018
     */
    CleverGenerator();

    /**
     * @brief      Gets a random int
     *
     * @param[in]  min   The minimum
     * @param[in]  max   The maximum
     *
     * @return     The int.
     *
     * @author     mochiwa
     * @date       31-Dec-2018
     */
    int getInt(int min=0,int max=100);

    /**
     * @brief      Gets a random double.
     *
     * @param[in]  min   The minimum
     * @param[in]  max   The maximum
     *
     * @return     The double.
     *
     * @author     mochiwa
     * @date       31-Dec-2018
     */
    double getDouble(double min=0,double max=100);

    /**
     * @brief      Gets the boolean.
     *
     * @return     The boolean.
     *
     * @author     mochiwa
     * @date       05-Jan-2019
     */
    int getBoolean();

    /**
     * @brief      Gets the date.
     *
     * @return     The date.
     *
     * @note       return date as YYYYMMDD
     *
     * @author     mochiwa
     * @date       02-Jan-2019
     */
    std::string const getDate();

    /**
     * @brief      Gets the date time.
     *
     * @return     The date time.
     *
     * @note       return date time as YYYYMMDD HH:MM:SS AM/PM
     *
     * @author     mochiwa
     * @date       02-Jan-2019
     */
    std::string const getDateTime();


    /**
     * @brief      Gets the clever value.
     *
     * @param      attribute  The attribute
     *
     * @return     The clever value.
     *
     * @note       this function try to find a coherence value for the attribute
     *
     * @author     mochiwa
     * @date       31-Dec-2018
     */
    std::string getCleverValue(std::string const& name);
};

#endif