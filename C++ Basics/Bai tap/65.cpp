#include <iostream>
#include <math.h>
#include <conio.h>
int main ()
{
	int i,j,k,a[8][8],s,max=0;
	for (i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			printf("Nhap vao so a[%d][%d] ",i,j);
			scanf("%d",&a[i][j]);
			
		}
	}
	for(i=0;i<8;i++)
	{
		s=0;
		for(j=0;j<8;j++)
		{
			s=s+abs(a[j][i]);
			
		}
		if(s>max)
		{
			k=i;
			max=s;
			
		}
	}
	int min=100;
	for(i=0;i<8;i++)
	{
		if(a[i][k]<min)
		{
			min=a[i][k];
		}
	}
	printf(" Gia tri de bai yeu cau la: %d",min);
	getch();
	
}
