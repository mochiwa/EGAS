#ifndef __WRITER_FACTORY_H__
#define __WRITER_FACTORY_H__

#include <iostream>

#include "SGBDType.h"
#include "SQLWriter.h"
#include "OracleWriter.h"
#include "PostgresWriter.h"
#include "MYSQLWriter.h"

class WriterFactory
{
public:
    static SQLWriter* getWriter(SGBDType const type);
};


#endif