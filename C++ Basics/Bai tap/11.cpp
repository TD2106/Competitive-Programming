#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
int main ()
{
	float x,y,z;
	cout <<"Nhap 3 so x,y,z "<<endl;
	cin>>x>>y>>z;
	cout <<"Ket qua cau a " << (3+exp(y-1))/(1+pow(x,2*abs(y-tan(z))))<<endl;
	cout <<"Ket qua cau b " << 1+abs(y-x)+pow(y-x,2)/2+pow(y-x,3)/3<<endl;
	cout <<"Ket qua cau c " << log(abs((y-sqrt(abs(x)))*(x-y/(z+pow(x,0.5)))))<<endl;
	cout <<"Ket qua cau d " << x-pow(x,3)/6-pow(x,5)/120<<endl;
	
}
