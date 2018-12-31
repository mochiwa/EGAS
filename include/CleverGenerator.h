#ifndef __CLEVERGENERATOR_H__
#define __CLEVERGENERATOR_H__

#include <iostream>
#include <cstdlib>
#include <random>

class CleverGenerator
{
private:
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
    
};

#endif