#include <iostream>
using namespace std;
int main ()
{
	int testcase,n,i;
	string s;
	cin>>testcase;
	while(testcase--)
	{
		cin>>n;
		if(n>1000000000||n<2)
		continue;
		else
		{
			getline(cin,s);
			for(i=0;i<n-1;i++)
			{
				if(s[i]=='1')
				{
					if(s[i+1]=='0')
					cout<<"OUTPUT "<<i<<"\n";
					else
					i++;
				}
			}
		}
	}
	return 0;
}
