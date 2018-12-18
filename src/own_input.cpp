#include "own/own_input.h"

using namespace std;


  /*******************************************************\
<| /////////////////--Reading Function--////////////////// |>
  \*******************************************************/

char readSingleChar(char const* cursor)
{
	char c;
	cin.clear();
	cin>>c;
	cin.ignore(10000,'\n');
	return c;
}

int readInteger(char const* cursor)
{
	int integer;
	string input;
	do
	{
		cout<<cursor;
		cin>>input;
		cin.ignore(10000,'\n');
		integer=atoi(input.c_str());
	}while(!integer);
	return integer;
}

double readDouble(char const* cursor)
{
	double doub;
	string input;
	do
	{
		cout<<cursor;
		getline(cin,input);
		doub=atof(input.c_str());
	}while(!doub);
	return doub;
}

bool getBinaryAnswer(char const* output)
{
	char answer;
	while(true)
	{
		cout<<output<<" (y/n) :";
		answer=readSingleChar(output);
		if(answer=='y')
			return true;
		if(answer=='n')
			return false;
	}
}

void resetChar(char *str,int size)
{
	int i;
	for(i=0;i<size-1;++i)
		str[i]=0;
	str[i]='\0';
}

