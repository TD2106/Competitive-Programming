#include <iostream>
using namespace std;
#include <math.h>
int main ()
{
	float x,y,A,B,C,d;
	cout <<"Nhap x va y "<<endl;
	cin >> x >> y;
	cout <<"Nhap A,B,C cua mat phang co dang Ax+By+C "<<endl;
	cin >>A>>B>>C;
	cout <<"Khoang cach la: "<<(A*x+B*y+C)/sqrt(A*A+B*B);
	
}
