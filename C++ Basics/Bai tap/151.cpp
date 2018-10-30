#include <iostream>
using namespace std;
int main ()
{
	int n,m,a1,b1,a2,b2,max=0,min=1000;
	cout <<"Nhap n va m "<<endl;
	cin>>n>>m;
	int mang[m][n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"Nhap phan tu hang "<<i<<" cot "<<j<<" : ";
			cin>>mang[i][j];
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<mang[i][j]<<" ";
		}
		cout<<endl;
	}
	int check=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(mang[i][j]<min)
			{
				min = mang[i][j];
				a1=i;
				b1=j;
			}
		}
		for(int j=0;j<m;j++)
		{
			if(mang[j][b1]>max)
			{
				max=mang[j][b1];
				a2=j;
			}
		}
		if(max==min&&a1==a2)
		{
			check =1;
			break;
		}
		else
		{
			max=0;
			min=1000;
		}
	}
	if(check==1)
	cout<<"Phan tu yen ngua o hang "<<a1<<" cot "<<b1<<": "<<max;
	else
	cout <<"Ko co";
	return 0;
}
