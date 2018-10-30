#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main ()
{
	int mark,move,mark2;
	char num[3];
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='.')
		{
			mark=i;
		}
		if(s[i]=='e')
		{
			for(int j=i+1;j<s.size();j++)
			{
				num[j-i-1]=s[j];
			}
			break;
		}
	}
	sscanf(num,"%d",move);
}
