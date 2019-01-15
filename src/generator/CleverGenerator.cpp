#include "CleverGenerator.h"

using namespace std;

CleverGenerator::CleverGenerator()
{
}

int CleverGenerator::getInt(int min,int max)
{
    return generator.randomInt(min,max-1);
}

double CleverGenerator::getDouble(double min,double max)
{
    return generator.randomDouble(min,max-1);
}

int CleverGenerator::getBoolean()
{
    return generator.randomBool();
}

string CleverGenerator::getCleverValue(string const& name)
{
    return name;
}

string const CleverGenerator::getDate()
{
    int year=getInt(1950,2018);
    int month=getInt(1,12);
    int day=0;

    if(month==2)
        day=getInt(1,27); // in my world, february doesn't have 29 days ! ;)
    else
        day=getInt(1,28);

    return to_string(year)+"-"+to_string(month)+"-"+to_string(day);
}

string const CleverGenerator::getDateTime()
{
    int hour=getInt(1,12);
    int minute=getInt(1,59);
    int second=getInt(1,59);
    string period="";

    if(getInt()%2==0)
        period="AM";
    else
        period="PM";
    return getDate()+" "+to_string(hour)+":"+to_string(minute)+":"+to_string(second)+" "+period;
}