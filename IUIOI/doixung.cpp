#include <iostream>
using namespace std;
int main ()
{
	string s;
	int t,check;
	cin>>t;
	cin.ignore();
	while(t--)
	{
		check=1;
		cin>>s;
		for(int i=0;i<s.size()/2;i++)
		{
			if(s[i]!=s[s.size()-1-i])
			{
				check=0;
				break;
			}
		}
		if(check)
		cout<<"YES\n";
		else
		cout<<"NO\n";
	}
	return 0;
}
