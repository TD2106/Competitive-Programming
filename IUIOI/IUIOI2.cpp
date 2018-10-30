#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	getchar();
	char str[10];
	char *pEnd;
	float temp;
	while(n--)
	{
		fgets(str,10,stdin);
		if(str[1]=='a'||str[1]=='A')
		{
			cout<<"NaN\n";
			continue;
		}
		else
		{
			if(str[1]=='n'||str[2]=='n'||str[1]=='N'||str[2]=='N')
			{
				cout<<"0\n";
				continue;
			}
			else
			{
				if(str[0]=='-'&&str[1]=='0')
				{
					cout<<"-inf\n";
					continue;
				}
				else
				{
					temp=strtof (str, &pEnd);
					printf("%f\n",1.0/temp);
					continue;
				}
			}
		}
	}
	return 0;
}
