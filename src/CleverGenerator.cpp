#include "CleverGenerator.h"

using namespace std;

CleverGenerator::CleverGenerator()
{
    generator.seed(r());
}


int CleverGenerator::getInt(int min,int max)
{
    uniform_int_distribution<int> distribution(min,max);
    return distribution(generator);
}

double CleverGenerator::getDouble(double min,double max)
{
    uniform_real_distribution<double> distribution(min,max);
    return round(distribution(generator)*100)/100.0;
}

string CleverGenerator::getCleverValue(string const& name)
{
    return "tes";
}