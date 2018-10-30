#include <iostream>
using namespace std;
int main ()
{
	int n;
	cout<<"Nhap n: ";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		a[i]=0;
		cout<<a[i];
	}
	cout<<endl;
	int check=0;
	while(check!=1)
	{
		check =1;
		for(int i=n-1;i>=0;i--)
		{
			if(a[i]==0)
			{
				a[i]=1;
				check=0;
				for(int j=i+1;j<n;j++)
				a[j]=0;
				break;
			}
		}
		if(check==1)
		break;
		for(int i=0;i<n;i++)
		cout<<a[i];
		cout<<endl;
	}
	return 0;
}
