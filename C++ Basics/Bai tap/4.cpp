#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	float a,b,c,p;
	cout <<"Nhap 3 canh ban a,b,c "<<endl;
	cin >>a>>b>>c;
	p=(a+b+c)/2;
	cout <<"Dien tich cua tam giac la: "<<sqrt(p*(p-a)*(p-b)*(p-c));
	
}
