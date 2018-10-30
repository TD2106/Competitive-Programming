#include <iostream>
using namespace std;
int main ()
{
	int n,a,b;
	cout<<"Nhap n ";
	cin>>n;
	int check = 1;
	for(a=1;a<n/3;a++)
	{
		b=(n-3*a)/5;
		if(3*a+5*b==n)
		{
			cout<<a<<" "<<b<<endl;
			check=0;
			break;
		}
	}
	if(check)
	cout<<"Ko co 2 so a va b thoa"<<endl;
	return 0;
}
