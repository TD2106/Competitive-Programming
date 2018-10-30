#include <iostream>
#include <math.h>
#include <conio.h>

using namespace std;


float t (float x)
{
	
	int s,k;
	float a,b,c,d,e;
	c=0.0;
	d=0.0;
	for (int i=1;i<=10;i++)
	{
		int s=1;
		int k=1;
		for(int j=1;j<=(2*i+1);j++)
		{
			s=s*j;
		}
		a=pow(x,(2*i+1)*1.0)/s;
		c=c+a;
		for (int l=1;l<=2*i;l++)
		{
			k=k*l;
		}
		b=pow(x,2*i*1.0)/k;
		d=d+b;
		
	
	}
	e=c/d;
	return e;
}

int main ()
{
	float y;
	printf("Nhap vao so y ");
	scanf("%f",&y);
	float a = (1.7*t(0.25)+2*t(1+y))/6-t(y*y-1);
	cout << a << endl;
	getch();
	
}
