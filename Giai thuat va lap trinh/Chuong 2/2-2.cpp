#include <iostream>
using namespace std;
int main ()
{
	int n,k;
	cin>>n>>k;
	int mang[k];
	for(int i=0;i<k;i++)
	{
		mang[i]=0;
		cout<<mang[i]<<" ";
	}
	cout<<endl;
	int check;
	while(1)
	{
		check=1;
		for(int i=k-1;i>=0;i--)
		{
			if(mang[i]==n-1)
			continue;
			if(mang[i]<n-1)
			{
				for(int j=i+1;j<k;j++)
				mang[j]=0;
				check=0;
				mang[i]=mang[i]+1;
				break;
			}
		}
		if(check)
		break;
		for(int i=0;i<k;i++)
		cout<<mang[i]<<" ";
		cout<<endl;
	}
	return 0;
}
