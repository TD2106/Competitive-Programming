#include <iostream>
#include <map>
using namespace std;
int main ()
{
	map<char,int> data;
	int tc;
	string s;
	cin>>tc;
	cin.ignore();
	while(tc--)
	{
		data.clear();
		cin>>s;
		bool check=1;
		for(int i=0;i<s.size();i++)
		{
			if(data[s[i]]==0)
			data[s[i]]==1;
			else
			{
				cout<<"Yes\n";
				check=0;
				break;
			}
		}
		if(check)
		cout<<"No\n";
	}
	return 0;
}

