#include <iostream>
using namespace std;
int main ()
{
	int n,temp,a=0;
	cout<<"Nhap n ";
	cin>>n;
	int mang[n];
	cout<<"Hoan vi la: ";
	for(int i=0;i<n;i++)
	{
		mang[i]=i+1;
		cout<<mang[i]<<" ";
	}
	cout<<endl;
	int check = 0,dem2;
	while(check!=1)
	{
		check = 1;
		for(int i=n-1;i>=0;i--)
		{
			if(mang[i]<mang[i+1])
			{
				dem2=n-1;
				check = 0;
				for(int j=n-1;j>i;j--)
				{
					if(mang[j]>mang[i])
					{
						temp=mang[j];
						mang[j]=mang[i];
						mang[i]=temp;
						break;
					}
				}
				for(int j=i+1;j<i+1 + (n-i-1)/2;j++)
				{
					temp=mang[j];
					mang[j]=mang[dem2];
					mang[dem2]=temp;
					dem2--;	
				}
				break;
			}
		}
		if(check==1)
		break;
		cout<<"Hoan vi la: ";
		for(int j=0;j<n;j++)
		cout<<mang[j]<<" ";
		cout<<endl;
	}
	return 0;
}
