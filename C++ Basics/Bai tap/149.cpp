#include <iostream>
using namespace std;
int main ()
{
	int n,m;
	cout<<"Nhap n ";
	cin>>n;
	cout<<"Nhap m ";
	cin>>m;
	int mang[n],s;
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap mang["<<i<<"]";
		cin>>mang[i];
	}
	int i,j,check=0;
	for(i=0;i<n;i++)
	{
		s=0;
		for(j=i;j<n;j++)
		{
			s=s+mang[j];
			if(s==m)
			{
				check=1;
				break;
			}
		}
		if(check==1)
		break;
	}
	if(check==0)
	{
		cout<<"Ko co day con phu hop ";
		exit(0);
	}
	for(int temp=i;temp<=j;temp++)
	{
		if(temp==j)
		cout<<mang[temp]<<"="<<m;
		else
		cout<<mang[temp]<<"+";
	}
	
}
