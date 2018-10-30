#include <iostream>
using namespace std;
#include <math.h>
int main ()
{
	float a,b,c;
	cout <<"Nhap canh goc vuong ";
	cin >>a;
	cout <<"Nhap canh huyen lon hon canh goc vuong ";
	cin >>b;
	c=sqrt(b*b-a*a);
	float p=(a+b+c)/2;
	cout <<"Ban kinh duong tron noi tiep la: "<<sqrt(((p-a)*(p-b)*(p-c))/p);
}
