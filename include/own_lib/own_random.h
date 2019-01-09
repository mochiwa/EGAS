#ifndef __OWN_RANDOM_H__
#define __OWN_RANDOM_H__

#include <iostream>
#include <random>

class own_random
{
private:
    std::random_device r_seed;
    std::default_random_engine generator;
public:
    own_random();

    /**
     * @brief      get a random int between two values
     *
     * @param[in]  min   The minimum, 0 is the default value
     * @param[in]  max   The maximum, 100 is the default value
     *
     * @author     mochiwa
     * @date       06-Jan-2019
     */
    int randomInt(int min=0,int max=100);

     /**
      * @brief      get a random double between two values
      *
      * @param[in]  min   The minimum, 0 is the default value
      * @param[in]  max   The maximum, 100 is the default value
      *
      * @author     mochiwa
      * @date       06-Jan-2019
      */
    double randomDouble(double min=0,double max=100);

    /**
     * @brief      get a random boolean
     *
     * @author     mochiwa
     * @date       06-Jan-2019
     */
    bool randomBool();
    
};

#endif