#include <iostream>
using namespace std;
int main ()
{
	long long tc,sum=0,temp;
	string s;
	cin>>tc;
	cin.ignore();
	while(tc--)
	{
		sum=0;
		cin>>s;
		for(int i=0;i<s.size();i++)
		{
			temp=s[i]-'0';
			sum+=temp;
			sum%=9;
		}
		cout<<sum<<endl;
	}
	return 0;
}
