#include <iostream>
using namespace std;
int main ()
{
	int n;
	cout<<"Nhap so n: ";
	cin>>n;
	int matrix[n][n],a;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"Nhap phan tu hang "<<i<<" cot "<<j<<" : ";
			cin>>matrix[i][j];
		}
	}
	cout<<"Ma tran da nhap la: "<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<n;i++)
	{
		a=matrix[n-1][i];
		matrix[n-1][i]=matrix[i][n-1];
		matrix[i][n-1]=a;
	}
	cout<<"Ma tran thay doi la: "<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}
