#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int tc,n,alphabets[26];
bool cmp(string s1,string s2)
{
	int size=min(s1.size(),s2.size());
	for(int i=0;i<size;i++)
	{
		if(alphabets[s1[i]-'a']<alphabets[s2[i]-'a'])
		return true;
		else if(alphabets[s1[i]-'a']>alphabets[s2[i]-'a'])
		return false;
	}
	if(s1.size()<s2.size())
	return true;
	else
	return false;
}
int main ()
{
	cin>>tc;
	while(tc--)
	{
		memset(alphabets,0,sizeof(alphabets));
		string s;
		vector<string> data;
		cin>>s;
		for(int i=0;i<s.size();i++)
		alphabets[s[i]-'a']=i;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>s;
			data.push_back(s);
		}
		sort(data.begin(),data.end(),cmp);
		for(int i=0;i<n;i++)
		cout<<data[i]<<endl;
	}
	return 0;
}
