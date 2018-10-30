#include <iostream>
#include <bitset>
using namespace std;
int main ()
{
	bool check;
	bitset<5001> daynhiphan;
	string s;
	cin>>s;
	cin.ignore();
	for(int i=0;i<s.size();i++)
	{
		daynhiphan[i+1]=s[i]-'0';
	}
	int m,L,R;
	cin>>m;
	while(m--)
	{
		check=1;
		cin>>L>>R;
		int length=(R-L+1)/2;
		for(int i=0;i<length;i++)
		{
			if(daynhiphan[R-i]!=daynhiphan[L+i])
			{
				check=0;
				break;
			}
		}
		if(check)
		{
			cout<<"YES\n";
		}
		else
		cout<<"NO\n";
	}
	return 0;
}
