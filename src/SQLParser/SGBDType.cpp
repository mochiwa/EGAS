#include "SGBDType.h"

using namespace std;

ostream& operator<<(ostream& os,SGBDType const type)
{
    switch(type)
    {
        case MYSQL: os<<"MYSQL";break;
        case ORACLE: os<<"ORACLE";break;
        case POSTGRES: os<<"POSTGRES";break;
        default:os<<"WTF !";os.setstate(std::ios_base::failbit);
    }
    return os;
}