#include <iostream>
#include <set>
using namespace std;
int main ()
{
	string s,temp[26];
	for(int i=0;i<26;i++)
	{
		char a='a'+i;
		temp[i]+=a;
	}
	set<string> data;
	cin>>s;
	for(int i=0;i<26;i++)
	{
		data.insert(temp[i]+s);
		data.insert(s+temp[i]);
	}
	for(int i=0;i<s.size()-1;i++)
	{
		for(int j=0;j<26;j++)
		{
			string input=s.substr(0,i+1)+temp[j]+s.substr(i+1);
			data.insert(input);
		}
	}
	cout<<data.size();
	return 0;
}
