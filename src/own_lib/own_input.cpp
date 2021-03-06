#include "own_input.h"

using namespace std;


  /*******************************************************\
<| /////////////////--Reading Function--////////////////// |>
  \*******************************************************/

int own::readInteger(string const& cursor)
{
	string input="";
	do
	{
		cout<<cursor;
		getline(cin,input);
	}while(!isNumber(input));

	return atoi(input.c_str());
}

double own::readDouble(string const& cursor)
{
	string input="";

	do
	{
		cout<<cursor;
		getline(cin,input);
	}while(!isNumber(input));

	return atof(input.c_str());
}

bool own::getBinaryAnswer(string const& output)
{
	string input="";
	while(true)
	{
		cout<<output<<" (y/n)"<<endl;
		getline(cin,input);
        if(!input.compare("y") || !input.compare("Y") || !input.compare("1"))
		  return true;
		if(!input.compare("n") || !input.compare("N") || !input.compare("0"))
			return false;
	}
}

bool own::isNumber(std::string const& str)
{
    for(char c : str)
    {
        if((c!=45 && c!=46) &&  (c<48 || c>57))
            return false;
    }
    return true;
}


void own::proceed(std::string const& str)
{
    cout<<str;
    cin.get();   
}


void own::showTitle(std::string str,unsigned int lineSize)
{
    unsigned int i;
    unsigned int lineUp;
    unsigned int lineDown;

    if(str.length()%2==0)
        lineUp=lineDown=lineSize;
    else
        lineUp=lineDown=lineSize-1;
    for(i=0;i<lineUp;++i)
        cout<<"#";

    cout<<endl<<"##";
    lineUp-=2;
    for(i=0;i<((lineUp-str.length())/2);++i)
        cout<<" ";

    cout<<str;

    lineUp-=3;
    for(i=0;i<((lineUp-str.length())/2);++i)
        cout<<" ";
    cout<<"##"<<endl;

    for(i=0;i<lineDown;++i)
        cout<<"#";
    cout<<endl;
}