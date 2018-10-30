#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <map>
#include <string>
using namespace std;

void processstr(string &s,string &name1, string &name2)
{
	int mark1,mark2,check=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='#'||s[i]=='@')
		{
			if(s[i]=='#'&&check%2==1)
			{
				mark1=i;
				check++;
			}
			else if(s[i]=='#'&&check%2==0)
			{
				mark2=i;
				check++;
			}
			s[i]=' ';
		}
	}
	name1=s.substr(0,mark1);
	name2=s.substr(mark2+1,s.size()-mark2-1);
}
int main ()
{
	string s;
	getline(cin,s);
	string name1,name2;
	processstr(s,name1,name2);
	cout<<name1;
}

