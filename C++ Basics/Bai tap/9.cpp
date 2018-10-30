#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	float a,b,c,p;
	cout <<"Nhap 3 canh ban a,b,c "<<endl;
	cin >>a>>b>>c;
	p=(a+b+c)/2;
	float s=sqrt(p*(p-a)*(p-b)*(p-c));
	cout <<"Chieu cao ung voi canh a "<<2*s/a<<endl;
	cout <<"Chieu cao ung voi canh b "<<2*s/b<<endl;
	cout <<"Chieu cao ung voi canh c "<<2*s/c<<endl;
	cout <<"Trung tuyen canh a "<<sqrt(((b*b+c*c)/2)-(a*a/4))<<endl;
	cout <<"Trung tuyen canh b "<<sqrt(((a*a+c*c)/2)-(b*b/4))<<endl;
	cout <<"Trung tuyen canh c "<<sqrt(((b*b+a*a)/2)-(c*c/4))<<endl;
	cout <<"Duong phan giac ung voi canh a "<< (2*sqrt(b*c*p*(p-a))/(b+c))<<endl;
	cout <<"Duong phan giac ung voi canh b "<< (2*sqrt(a*c*p*(p-b))/(a+c))<<endl;
	cout <<"Duong phan giac ung voi canh c "<< (2*sqrt(b*a*p*(p-c))/(b+a))<<endl;
}
