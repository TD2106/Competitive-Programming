#include <iostream>
#include <math.h>
using namespace std;
int c=0;
int check(int n)
{
	int b;
	if(n%2==0)
	b=n/2;
	if(n%2!=0)
	{
		b=n*3+1;
		b=n/2;
	}
	c++;
	if(b==1)
	return c;
	else
	check(b);
}

int main()
{
	int n;
	cout<<"Nhap so n: ";
	cin >>n;
	cout<<"Sau "<<check(n)<<" lan lap thi ta dc ket qua"<<endl;
	return 0;
}
