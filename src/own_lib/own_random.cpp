#include "own_random.h"

using namespace std;

own_random::own_random()
{
    generator.seed(r_seed());
}

int own_random::randomInt(int min,int max)
{
    uniform_int_distribution<int> distribution(min,max);
    return distribution(generator);
}

double own_random::randomDouble(double min,double max)
{
    uniform_real_distribution<double> distribution(min,max);
    return round(distribution(generator)*100)/100.0;
}

bool own_random::randomBool()
{
    return randomInt()%2==0;
}