#include "ReaderFactory.h"

using namespace std;

TableReader* ReaderFactory::getReader(SGBDType type) 
{
    switch(type)
    {
        case MYSQL:
            return new MYSQLTableReader();
        case ORACLE:
            return new OracleReader();
        case POSTGRES:
            return new PostgresReader();
        default:
            break;
    }
    return nullptr;
}
