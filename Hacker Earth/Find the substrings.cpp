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
		cin>>s;
		long long len=s.size(),ans=len*(len+1)/2;
		long long a=0,b=0,c=0;
		for(long long i=0;i<len;i++)
		{
			if(s[i]=='a')
			{
				a=i+1;
				ans-=min(b,c);
			}
			if(s[i]=='b')
			{
				b=i+1;
				ans-=min(a,c);
			}
			if(s[i]=='c')
			{
				c=i+1;
				ans-=min(a,b);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
