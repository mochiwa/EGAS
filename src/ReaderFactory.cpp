#include "ReaderFactory.h"

using namespace std;

TableReader* ReaderFactory::getReader(SGBDType type) 
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
