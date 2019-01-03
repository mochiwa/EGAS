#include "MYSQLWriter.h"



void MYSQLWriter::appendDate(std::string const& value)
{
    query+="STR_TO_DATE('"+value+"','%Y-%m-%d '),";
}

void MYSQLWriter::appendDateTime(std::string const& value)
{
    query+="STR_TO_DATE('"+value+"','%Y-%m-%d %H:%i:%s %p'),";
}