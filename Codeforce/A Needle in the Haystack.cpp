#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool comp(int arr1[26],int arr2[26])
{
	for(int i=0;i<26;i++)
	{
		if(arr1[i]!=arr2[i])
		return 0;
	}
	return 1;
}
int main ()
{
	int tc,arr1[26],arr2[26];
	string pat,s;
	cin>>tc;
	cin.ignore();
	while(tc--)
	{
		memset(arr1,0,sizeof(arr1));
		memset(arr2,0,sizeof(arr2));
		cin>>pat;
		for(int i=0;i<pat.size();i++)
		arr1[pat[i]-'a']++;
		cin>>s;
		bool check=0;
		for(int i=0;i<pat.size()&&i<s.size();i++)
		{
			arr2[s[i]-'a']++;
		}
		if(comp(arr1,arr2))
		{
			cout<<"YES\n";
			continue;
		}
		else
		{
			for(int i=pat.size();i<s.size();i++)
			{
				arr2[s[i-pat.size()]-'a']--;
				arr2[s[i]-'a']++;
				if(comp(arr1,arr2))
				{
					cout<<"YES\n";
					check=1;
					break;
				}
			}
			if(!check)
			cout<<"NO\n";
		}
	}
	return 0;
}
