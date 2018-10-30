#include <iostream>
#include <math.h>
using namespace std;
int main ()
{
	int n;
	float R;
	cout <<"Nhap ban kinh (cm) ";
	cin >> R;
	cout <<"Nhap n so canh ";
	cin >> n;
	float a=3.14/(1.0*n);
	cout <<"Chu vi da giac noi tiep duong tron ban kinh R la "<< n*R*2*sin(a)<<" cm";
	return 0;
}
