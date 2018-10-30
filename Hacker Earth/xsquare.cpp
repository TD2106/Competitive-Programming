#include <iostream>
#include <bitset>
using namespace std;
int main ()
{
	string s1,s2;
	int t;
	bitset<128> mark;
	cin>>t;
	cin.ignore();
	while(t--)
	{
		int check=0;
		getline(cin,s1);
		getline(cin,s2);
		for(int i=0;i<s1.size();i++)
		{
			mark[s1[i]-'A']=1;
		}
		for(int i=0;i<s2.size();i++)
		{
			if(mark[s2[i]-'A'])
			{
				check=1;
				break;
			}
		}
		if(check)
		cout<<"YES\n";
		else
		cout<<"NO\n";
		mark.reset();
	}
	return 0;
}
