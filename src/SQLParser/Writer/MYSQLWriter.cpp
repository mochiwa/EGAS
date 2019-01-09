#include "MYSQLWriter.h"

using namespace std;

void MYSQLWriter::appendDate(string const& value)
{
    query+="STR_TO_DATE('"+value+"','%Y-%m-%d '),";
}

void MYSQLWriter::appendDateTime(string const& value)
{
    query+="STR_TO_DATE('"+value+"','%Y-%m-%d %H:%i:%s %p'),";
}

string MYSQLWriter::formatedWord(string const& word)
{
    string cpy;

    for(char c:word)
    {
        for(char reserved:RESERVED_CHAR)
            if(reserved==c)
                cpy+="\\";
        cpy+=c;
    }
    return cpy;
}