#include <iostream>
#include <math.h>
#include <conio.h>
int main ()
{
	int i,j,c,b;
	float x,a[26],d,min=100.0;
	printf(" Nhap vao x: ");
	scanf("%f",&x);
	for(i=1;i<=25;i++)
	{
		printf("Nhap vao phan tu a[%d] ",i);
		scanf("%f",&a[i]);
		
	}
	for(i=1;i<=24;i++)
	{
		for(j=i+1;j<=25;j++)
		{
			d=((a[i]+a[j])/2);
		    if(abs(x-d)<=min)
		    {
		    	min=abs(x-d);
				c=i;
		    	b=j;
			}
		    
		}
	}
	printf(" 2 so thoa de bai la %f va %f ",a[c],a[b]);
	getch();
}
