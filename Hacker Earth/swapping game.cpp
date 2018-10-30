#include <iostream>
#include <algorithm>
using namespace std;
int precompute(string initial)
{
	int cnt=0;
	string s=initial,pre,sub,ans;
	while(ans!=initial)
	{
		pre.clear();
		sub.clear();
		cnt++;
		for(int i=0;i<s.size();i+=2)
		pre+=s[i];
		for(int i=1;i<s.size();i+=2)
		{
			if(i+1==s.size())
			pre+=s[i];
			else
			sub+=s[i];
		}
		reverse(sub.begin(),sub.end());
		s=pre+sub;
		ans=s;
	}
	return cnt;
}
int main ()
{
	int k;
	string initial,s;
	cin>>k>>initial;
	s=initial;
	k%=precompute(initial);
	while(k--)
	{
		string pre,sub;
		for(int i=0;i<s.size();i+=2)
		pre+=s[i];
		for(int i=1;i<s.size();i+=2)
		{
			if(i+1==s.size())
			pre+=s[i];
			else
			sub+=s[i];
		}
		reverse(sub.begin(),sub.end());
		s=pre+sub;
	}
	cout<<s<<endl;
}
