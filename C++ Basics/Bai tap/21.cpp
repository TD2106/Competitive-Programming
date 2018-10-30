#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	//cau a
	int n;
	cout<<"Nhap n ";
	cin>>n;
	cout<<pow(2,n)<<endl;
	//cau b
	int s=1;
	for(int i=1;i<=n;i++)
	s=s*i;
	cout<<s<<endl;
	//cau c
	float c=1.0;
	for(int i=1;i<=n;i++)
	{
		float temp=1/pow(i,2);
		c=c*(1+temp);
	}
	cout<<c<<endl;
	//cau d
	float d=0;
	for(int i=1;i<=n;i++)
	d=sqrt(2+d);
	cout<<d<<endl;
}
