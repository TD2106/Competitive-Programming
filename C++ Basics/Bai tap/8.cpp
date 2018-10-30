#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	float a,b,c,d;
	cout <<"Nhap day be ";
	cin >> a;
	cout <<"Nhap day lon ";
	cin >>b;
	d=(b-a)/2;
	cout <<"Nhap goc day ";
	cin >>c;
	c=c*3.14/180;
	cout <<"Dien tich hinh thang la "<<((tan(c)*d)*(a+b))/2<<endl;
	return 0;
}
