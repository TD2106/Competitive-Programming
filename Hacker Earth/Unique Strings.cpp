#include <iostream>
#include <bitset>
using namespace std;
int main ()
{
	bitset<26> check;
	string s,res;
	int tc;
	cin>>tc;
	while(tc--)
	{
		cin>>s;
		check.reset();
		res.clear();
		for(int i=0;i<s.size();i++)
		{
			if(!check[s[i]-'a'])
			{
				res+=s[i];
				check[s[i]-'a']=1;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
