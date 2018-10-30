#include <iostream>
using namespace std;
bool pospalin(string s)
{
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-i-1])
		{
			if(s[i]!='/'&&s[s.size()-i-1]!='/')
			return 0;
		}
	}
	return 1;
}
int main ()
{
	long long cnt;
	int tc,a,b;
	cin>>tc;
	while(tc--)
	{
		cnt=0;
		string s;
		cin>>s;
		cin>>a>>b;
		if(!pospalin(s))
		cout<<"-1\n";
		else
		{
			for(int i=0;i<s.size()/2;i++)
			{
				if(s[i]!=s[s.size()-i-1]||s[i]=='/'&&s[s.size()-i-1]=='/')
				{
					if(s[i]=='/'&&s[s.size()-i-1]=='/')
					cnt+=2*min(a,b);
					else if(s[i]=='a'||s[s.size()-i-1]=='a')
					cnt+=a;
					else
					cnt+=b;
				}
			}
			if(s.size()%2)
			{
				if(s[s.size()/2]=='/')
				cnt+=min(a,b);
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}
