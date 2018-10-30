#include <iostream>
#include <algorithm>
#include <bitset>
#include <cstring>
using namespace std;
int main ()
{
	bitset<100001> mark;
	mark[1]=1;
	mark[0]=0;
	for(int i=2;i*i<=100000;i++)
	{
		if(!mark[i])
		{
			for(int j=i*i;j<=100000;j+=i)
			mark[j]=1;
		}
	}
	/*for(int i=0;i<=200;i++)
	{
		if(!mark[i])
		cout<<i<<endl;
	}*/
	int tc,arr[30],cnt;
	string s;
	cin>>tc;
	cin.ignore();
	while(tc--)
	{
		bool flag=1;
		cnt=0;
		memset(arr,0,sizeof(arr));
		cin>>s;
		for(int i=0;i<s.size();i++)
		{
			if(!arr[s[i]-'a'])
			cnt++;
			arr[s[i]-'a']++;
		}
		if(mark[cnt])
		{
			cout<<"NO\n";
			continue;
		}
		for(int i=0;i<30;i++)
		{
			if(mark[arr[i]])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		cout<<"YES\n";
		else
		cout<<"NO\n";
	}
	return 0;
}
