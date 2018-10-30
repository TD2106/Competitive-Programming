#include <iostream>
#include <cstring>
using namespace std;
int degree[5000001];
void cal(int i,string s)
{
	int temp;
	if(i==1)
	degree[i]=1;
	else
	{
		if(degree[i-1]&&s[i-2]!=s[i-1])
		{
			degree[i]=0;
			return;
		}
		if(i%2)
		temp=i/2+1;
		else
		temp=i/2;
		if(s.substr(0,i/2)==s.substr(temp))
		degree[i]=1+degree[i/2];
		else
		degree[i]=0;
	}
}
int main ()
{
	//freopen("palindromedegree.txt","r",stdin);
	memset(degree,0,5000001*sizeof(int));
	unsigned long long sum=0;
	string s;
	char temp;
	for(int i=1;cin>>temp;i++)
	{
		s+=temp;
		cal(i,s);
		sum+=(unsigned long long)degree[i];
	}
	cout<<sum;
	return 0;
}
