#include <iostream>
#include <string>
#include <bitset>
using namespace std;
char arr[100002];
int n,k,mark=0,init=1;
void check()
{
	if(mark%2==0&&arr[mark-1]=='4')
	{
		k=k%2;
	}
	else if(mark%2==1&&arr[mark+2]=='7')
	{
		k=k%2;
	}
}
void print()
{
	for(int i=1;i<=n;i++)
	{
		cout<<arr[i];
	}
}
int main ()
{
	//freopen("5A.txt","r",stdin);
	arr[0]=arr[100001]=0;
	char temp;
	string second;
	cin>>n>>k;
	cin.ignore();
	for(int i=1;cin>>arr[i];i++);
	while(k>0)
	{
		mark=0;
		for(int i=init;i<=n;i++)
		{
			if(arr[i]=='4'&&arr[i+1]=='7')
			{
				mark=i;
				break;
			}
		}
		if(mark==0)
		{
			print();
			break;
		}
		check();
		if(k==0)
		{
			print();
			break;
		}
		if(mark%2)
		arr[mark+1]='4';
		else
		arr[mark]='7';
		k--;
		if(k==0)
		{
			print();
			break;
		}
		init=mark-1;
	}
	return 0;
}
