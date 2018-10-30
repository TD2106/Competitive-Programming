#include <iostream>
#include <conio.h>
#include <math.h>





float g ( float a, float b)
{
	float g = (a*a+b*b)/(a*a + 2*a*b + 3*b*b + 4);
	return g;
}

int main()
{
	float a,b;
	printf(" Nhap a ");
	scanf("%f",&a);
	printf(" Nhap b ");
	scanf("%f",&b);
	float c=g(1.2,a)+g(b,a)-g(2*a-b,a*b);
	printf("%f",c);
	getch();
	
}
