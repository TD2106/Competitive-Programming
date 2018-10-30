#include <iostream>
#include <cstring>
using namespace std;
long long arr[3][100010];
int main ()
{
	long long tc,temp,ans;
	string s;
	cin>>tc;
	cin.ignore();
	while(tc--)
	{
		cin>>s;
		memset(arr,0,sizeof(arr));
		arr[3][0]=1;
		ans=0;
		for(int i=0;i<s.size();i++)
		{
			for(int j=0;j<3;j++)
			arr[j][i+1]=arr[j][i];
			if(s[i]>'c')
			continue;
			else
			arr[s[i]-'a'][i+1]++;
		}
		/*for(int i=0;i<3;i++)
		{
			for(int j=0;j<=s.size();j++)
			cout<<arr[i][j]<<" ";
			cout<<endl;
		}*/
		for(int i=1;i<=s.size();i++)
		{
			for(int j=i-1;j>=0;j--)
			{
				if(arr[0][i]-arr[0][j]==arr[1][i]-arr[1][j]&&arr[0][i]-arr[0][j]==arr[2][i]-arr[2][j])
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
