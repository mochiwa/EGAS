#include "MYSQLWriter.h"

using namespace std;

void MYSQLWriter::initFile()
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

void MYSQLWriter::initTable(string tableName,unsigned int lines)
{
    query+="/***********************************\\\n";
    query+="             "+tableName;
    query+="\n Line :"+to_string(lines);
    query+="\n\n\\***********************************/ \n";
    writeQuerry();
}

void MYSQLWriter::appendAttributes(vector<Attribute> const& attributes)
{
    for(Attribute const& att:attributes)
        if(att.getKeyType()!=KeyType::primary )
            query+=att.getName()+",";
    query.back()=')';
    query+=" VALUES (";
}

void MYSQLWriter::appendDate(string const& value)
{
    query+="STR_TO_DATE('"+value+"','%Y-%m-%d '),";
}

void MYSQLWriter::appendDateTime(string const& value)
{
    query+="STR_TO_DATE('"+value+"','%Y-%m-%d %h:%i:%s %p'),";
}

string MYSQLWriter::formatedWord(string const& word)
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