#include <iostream>
using namespace std;
int main ()
{
	int m;
	cout<<"Nhap m ";
	cin>>m;
	float a[m];
	for(int i=0;i<m;i++)
	{
		cout<<"Nhap a["<<i<<"] ";
		cin>>a[i];
	}
	int b,max=0,k,temp;
	for(int i=0;i<m;i++)
	{
		b=i;
		temp=0;
		for(int j=b+1;j<m;j++)
		{
			if(temp%2==0&&a[b]<a[j])
			{
				temp++;
				b=j;
			}
			else
			{
				if(temp%2!=0&&a[b]>a[j])
				{
					temp++;
					b=j;
				}
			}
		}
		if(temp>max)
		{
			max=temp;
			k=i;
		}
	}
	temp=0;
	for(int i=k+1;i<m;i++)
	{
		if(temp==0&&a[k]<a[i])
		{
			cout<<a[k]<<"<"<<a[i];
			temp++;
			k=i;
		}
		if(temp%2==0&&a[k]<a[i])
		{
			cout<<"<"<<a[i];
			temp++;
			k=i;
		}
		else
		{
			if(temp%2!=0&&a[k]>a[i])
			{
				cout<<">"<<a[i];
				temp++;
				k=i;
			}
		}
	}
	return 0;
}
