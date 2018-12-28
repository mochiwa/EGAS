#include "ReaderFactory.h"

using namespace std;

TableReader* ReaderFactory::getReader(ReaderType type) 
{
    switch(type)
    {
        case MYSQL:
            return new MYSQLTableReader();
        case ORACLE:
            return nullptr;
        default:
            break;
    }
    return nullptr;
}

std::ostream& operator<<(std::ostream& os,ReaderType reader)
{
    switch(reader)
    {
        case MYSQL   : os<<"MySQL"<<endl;   break;
        case ORACLE  : os<<"Oracle"<<endl;  break;
        default      : os.setstate(std::ios_base::failbit);
    }
    return os;
}