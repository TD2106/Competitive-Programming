#include <iostream>

using namespace std;

int giaithua(int n)
{
	if(n==0)
	return 1;
	else
	return n*giaithua(n-1);
}
int main()
{
	int n;
	cout <<"Nhap chieu cao cua tam giac Pascal: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			cout<<giaithua(i)/(giaithua(j)*giaithua(i-j))<<" ";
		}
		cout<<endl;
	}
}
