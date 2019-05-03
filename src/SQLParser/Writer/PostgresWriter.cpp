#include "PostgresWriter.h"

using namespace std;

void PostgresWriter::initFile()
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
    query+="  | | |          \\                         |   L \n";
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

void PostgresWriter::initTable(string tableName,unsigned int lines)
{
    query+="/***********************************\\\n";
    query+="             "+tableName;
    query+="\n Line :"+to_string(lines);
    query+="\n\n\\***********************************/ \n";
    writeQuerry();
}

void PostgresWriter::appendAttributes(vector<Attribute> const& attributes)
{
    for(Attribute const& att:attributes)
        if(att.getKeyType()!=KeyType::primary )
            query+=att.getName()+",";
    query.back()=')';
    query+=" VALUES (";
}

void PostgresWriter::appendDate(string const& value)
{
    query+="'"+value+"',";
}

void PostgresWriter::appendDateTime(string const& value)
{
    query+="STR_TO_DATE('"+value+"','%Y-%m-%d %h:%i:%s %p'),";
}

string PostgresWriter::formatedWord(string const& word)
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

void PostgresWriter::writeDrop(std::string const& tableName)
{
    query="";
    query+="DROP TABLE "+tableName+" CASCADE;"+'\n';
    writeQuerry();   
}