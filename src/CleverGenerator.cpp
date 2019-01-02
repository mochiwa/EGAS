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

string const CleverGenerator::getDate()
{
    int year=getInt(1950,2018);
    int month=getInt(1,12);
    int day=0;

    if(month==2)
        day=getInt(1,28); // in my world, february doesn't have 29 days ! ;)
    else
        day=getInt(1,31);

    return to_string(year)+"-"+to_string(month)+"-"+to_string(day);
}

string const CleverGenerator::getDateTime()
{
    int hour=getInt(0,11);
    int minute=getInt(0,59);
    int second=getInt(1,59);
    string period="";

    if(getInt()%2==0)
        period="AM";
    else
        period="PM";
    return getDate()+" "+to_string(hour)+":"+to_string(minute)+":"+to_string(second)+" "+period;
}