#include <iostream>
using namespace std;
int minis(char a,char b)
{
	if(a>b)
	return a-b;
	else
	return b-a;
}
int main ()
{
	int tc,sum;
	string s;
	cin>>tc;
	cin.ignore();
	while(tc--)
	{
		sum=0;
		cin>>s;
		for(int i=0;i<s.size()/2;i++)
		{
			if(s[i]!=s[s.size()-1-i])
			sum+=minis(s[i],s[s.size()-1-i]);
		}
		cout<<sum<<endl;
	}
	return 0;
}
