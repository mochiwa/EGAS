#include "WriterFactory.h"

SQLWriter* WriterFactory::getWriter(SGBDType const type)
{
    switch(type)
    {
        case MYSQL: return new MYSQLWriter();
        case ORACLE: return new OracleWriter();
        default: return nullptr;
    }
    return nullptr;
}