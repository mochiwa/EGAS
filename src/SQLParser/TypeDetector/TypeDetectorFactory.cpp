#include "TypeDetectorFactory.h"

using namespace std;

TypeDetector* TypeDetectorFactory::getDetector(SGBDType type)
{
    switch(type)
    {
        case MYSQL: 
           return new MYSQLTypeDetector();
        case ORACLE:
            return new OracleTypeDetector();
        case POSTGRES:
            return new PostgresTypeDetector();
        default: 
            break;
    }
    return nullptr;
}