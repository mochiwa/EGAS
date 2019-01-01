#ifndef __CLEVERGENERATOR_H__
#define __CLEVERGENERATOR_H__

#include <iostream>
#include <cstdlib>
#include <random>

class CleverGenerator
{
private:
    std::random_device r;
    std::default_random_engine generator;
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