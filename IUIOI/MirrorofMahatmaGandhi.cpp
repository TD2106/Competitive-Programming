#include <iostream>
using namespace std;
int main ()
{
	int tc;
	string s;
	cin>>tc;
	cin.ignore();
	while(tc--)
	{
		bool only=0;
		cin>>s;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]!='0'&&s[i]!='1'&&s[i]!='8')
			{
				only=1;
				break;
			}
		}
		if(only)
		{
			cout<<"NO\n";
		}
		else
		{
			bool check=1;
			for(int i=0;i<s.size()/2;i++)
			{
				if(s[i]!=s[s.size()-i-1])
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
	}
	return 0;
}
