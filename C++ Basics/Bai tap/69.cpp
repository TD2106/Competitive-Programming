#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;


float f1 ( float t, float s, float a)
{
	float i = (2*t-s-sin(a))/(5+abs(a) );
	return i;
}



int main ()
{
	
	float t, s;
	printf(" Nhap gia tri t ");
	scanf("%f",&t);
	printf(" Nhap gia tri s ");
	scanf("%f",&s);
	float b=f1(t,2*s,1.17)+f1(2.2,t,s-t);
	printf("%f",b);
	getch();
}

