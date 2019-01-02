#include "OracleWriter.h"

using namespace std;

void OracleWriter::appendDate(string const& value)
{
    query+="TO_DATE("+value+",'yyyy-mm-dd'),";
}

void OracleWriter::appendDateTime(string const& value)
{
    query+="TO_DATE("+value+",'yyyy-mm-dd hh:mi:ss PM'),";
}