#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	float a; int n;
	cout<<"Nhap a ";
	cin>>a;
	cout<<"Nhap n ";
	cin>>n;
	cout<<"Cau a: "<<pow(a,n)<<endl;
	float s=1,tong=0;
	for(int i=0;i<n;i++)
	s=s*(a+i*1.0);
	cout<<"Cau b: "<<s<<endl;
	s=1;
	for(int i=0;i<=n;i++)
	{
		s=1;
		for(int j=0;j<=i;j++)
		{
			s=s*(a+j*1.0);
		}
		tong=tong+1.0/s;
	}
	cout<<"Cau c: "<<tong<<endl;
}
