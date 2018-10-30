#include <iostream>
#include <cstdio>
using namespace std;
struct data
{
	char test;
	int money;
};
int main ()
{
	int n;
	cin>>n;
	while(n--)
	{
		int count;
		cin>>count;
		data price[count];
		for(int i=0;i<count;i++)
		{
			cin>>price[i].test;
			getchar();
			cin>>price[i].money;
			getchar();
		}
		string s;
		int line;
		cin>>line;
		getchar();
		int sum=0;
		while(line--)
		{
			getline(cin,s);
			for(int i=0;i<s.size();i++)
			{
				for(int j=0;j<count;j++)
				{
					if(s[i]==price[j].test)
				    {
				    	sum=sum+price[j].money;
				    	break;
					}
				}
			}
		}
		printf("%.2f$\n",(sum*1.0)/100);
	}
}
