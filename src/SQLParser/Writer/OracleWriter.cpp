#include "OracleWriter.h"

using namespace std;

void OracleWriter::appendDate(string const& value)
{
    query+="TO_DATE('"+value+"','yyyy-mm-dd'),";
}

void OracleWriter::appendDateTime(string const& value)
{
    query+="TO_DATE('"+value+"','yyyy-mm-dd hh:mi:ss PM'),";
}

string OracleWriter::formatedWord(string const& word)
{
    string cpy;

    for(char c:word)
    {
        for(char reserved:RESERVED_CHAR)
        {
            if(reserved==c)
                cpy+="\\";
        }
        cpy+=c;
    }
    return cpy;
}