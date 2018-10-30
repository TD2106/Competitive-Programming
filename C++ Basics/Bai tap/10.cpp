#include <iostream>
#include <math.h>

using namespace std;
int main ()
{
	float x1,y1,x2,y2,x3,y3;
	cout <<"Nhap x va y cua diem A "<<endl;
	cin >>x1>>y1;
	cout <<"Nhap x va y cua diem B "<<endl;
	cin >>x2>>y2;
	cout <<"Nhap x va y cua diem C "<<endl;
	cin >>x3>>y3;
	float a1,a2,a3,b1,b2,b3;
	a1=x1-x2;
	b1=y1-y2;
	a2=x2-x3;
	b2=y2-y3;
	a3=x1-x3;
	b3=y1-y3;
	cout <<"Dien tich tam giac la ";
	float S=0.5*(a1*b2-a2*b1);
	if(S>0)
	cout <<S;
	else
	cout <<S*(-1);
	cout <<endl<<"Chu vi tam giac la "<< sqrt(a1*a1+b1*b1)+sqrt(a2*a2+b2*b2)+sqrt(a3*a3+b3*b3);
}
