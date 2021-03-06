#include "OracleWriter.h"

using namespace std;

void OracleWriter::initFile()
{
    query+="/***************************************************************\\\n";
    query+="\n          File generated by EGAS application,";
    query+="\n          This application was created by Mochiwa\n";
    query+="                                                    / \n";
    query+="                                                  .7  \n";
    query+="                                       \\       , //  \n";
    query+="                                       |\\.--._/|//   \n";
    query+="                                      /\\ ) ) ).'/    \n";
    query+="                                     /(  \\  // /  \n";
    query+="                                    /(   J`((_/ \\ \n";
    query+="                                   / ) | _\\     / \n";
    query+="                                  /|)  \\  eJ    L \n";
    query+="                                 |  \\ L \\   L   L \n";
    query+="                                /  \\  J  `. J   L \n";
    query+="                                |  )   L   \\/   \\ \n";
    query+="                               /  \\    J   (\\   / \n";
    query+="             _....___         |  \\      \\   \\``` \n";
    query+="      ,.._.-'        '''--...-||\\     -. \\   \\ \n";
    query+="    .'.=.'                    `         `.\\ [ Y \n";
    query+="   /   /                                  \\]  J \n";
    query+="  Y / Y                                    Y   L \n";
    query+="  | | |          \\     Mochiwa             |   L \n";
    query+="  | | |           Y                        A  J \n";
    query+="  |   I           |                       /I\\ / \n";
    query+="  |    \\          I             \\        ( |]/| \n";
    query+="  J     \\         /._           /        -tI/ | \n";
    query+="   L     )       /   /'-------'J           `'-:. \n";
    query+="   J   .'      ,'  ,' ,     \\   `'-.__          \\ \n";
    query+="    \\ T      ,'  ,'   )\\    /|        ';'---7   / \n";
    query+="     \\|    ,'L  Y...-' / _.' /         \\   /   / \n";
    query+="      J   Y  |  J    .'-'   /         ,--.(   / \n";
    query+="       L  |  J   L -'     .'         /  |    /\\ \n";
    query+="       |  J.  L  J     .-;.-/       |    \\ .' / \n";
    query+="       J   L`-J   L____,.-'`        |  _.-'   | \n";
    query+="        L  J   L  J                  ``  J    | \n";
    query+="        J   L  |   L                     J    | \n";
    query+="         L  J  L    \\                    L    \\ \n";
    query+="         |   L  ) _.'\\                    ) _.'\\ \n";
    query+="         L    \\('`    \\                  ('`    \\ \n";
    query+="          ) _.'\\`-....'                   `-....' \n";
    query+="         ('`    \\ \n";
    query+="          `-.___/ \n";
    query+="\n\\***************************************************************/\n\n\n";
    writeQuerry();
}

void OracleWriter::initTable(string tableName,unsigned int lines)
{
    query+="/***********************************\\";
    query+="\n          Table: "+tableName;
    query+="\n  -Line generated: "+to_string(lines);
    query+="\n\\***********************************/ \n";
    writeQuerry();
}

void OracleWriter::appendAttributes(vector<Attribute> const& attributes)
{
    for(Attribute const& att:attributes)
        query+=att.getName()+",";
    query.back()=')';
    query+=" VALUES (";
}

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
        if(c=='\'')
            cpy+="'";
        cpy+=c;
    }
    return cpy;
}


void OracleWriter::writeDrop(std::string const& tableName)
{
    query="";
    query+="DROP TABLE "+tableName+" CASCADE CONSTRAINTS;"+'\n';
    writeQuerry();   
}