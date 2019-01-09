#include "WordGetter.h"

using namespace std;

WordGetter::WordGetter()
{
    count=0;
}

WordGetter::~WordGetter()
{
    if(file.is_open())
        file.close();
}

void WordGetter::openFile(std::string const& filename )
{
    try
    {
        file.exceptions ( ifstream::badbit| ifstream::failbit);
        if(file.is_open())
            file.close();
        file.open(filename);
    }catch(ifstream::failure& e)
    {
        cout<<"WordGetter: Exception during opening the file: "+filename<<endl;
    }
}


void WordGetter::countLine()
{
    int count=0;
    char c=0;

    try
    {
        while(file.get(c))
            if(c=='\n')
                count++;
    }catch(ifstream::failure e){}

    file.clear();
    file.seekg(0);
    setCountLine(count);
}


std::string WordGetter::selectWord()
{
    own_random gen;
    string str="";
    char c=0;
    int count=0;
    int random=gen.randomInt(0,getCountLine());

    file.clear();
    file.seekg(0);

    try
    {
        while(count != random)
            if(file.get()=='\n')
                count++;
    }
    catch(ifstream::failure e){}

    try
    {
        while((c=file.get())!='\n')
            str+=c;
    }
    catch(ifstream::failure e){}
    
    if(str.size()>=1)
        return str;
    else
        return selectWord();      
}


void WordGetter::setCountLine(unsigned int count)
{
    this->count=count;
}

unsigned int WordGetter::getCountLine()
{
    return count;
}


string WordGetter::getWord(string const& filename)
{
    WordGetter getter;
    getter.openFile(filename);
    getter.countLine();
    if(getter.getCountLine())
        return getter.selectWord();
    return "A_Word";
}

