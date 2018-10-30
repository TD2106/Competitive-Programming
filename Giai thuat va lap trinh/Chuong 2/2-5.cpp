#include <iostream>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	int mang[n];
	for(int i=0;i<n;i++)
	mang[i]=0;
	int check;
	while(1)
	{
		check =1;
		for(int i=n-1;i>=0;i--)
		{
			if(mang[i]==0)
			{
				check=0;
				mang[i]=1;
				for(int j=i+1;j<n;j++)
				mang[j]=0;
				break;
			}
		}
		if(check)
		break;
		for(int i=0;i<n;i++)
		if(mang[i]==1)
		cout<<i+1<<" ";
		cout<<endl;
	}
}
