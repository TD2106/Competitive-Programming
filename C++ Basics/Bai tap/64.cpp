#include <iostream>
#include <math.h>
#include <conio.h>
int main ()
{
	int m,n,i,j;
	printf("Nhap vao so n ");
	scanf("%d",&n);
	printf("Nhap vao so m ");
	scanf("%d",&m);
	float a[n+1][m+1],min[n+1],max=-100;
	for (i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			printf(" Nhap vao so thuc a[%d][%d] ",i,j);
			scanf("%f",&a[i][j]);
		}
	}
	for (i=1;i<=n;i++)
	{
		min[i]=100.0;
		max=-100.0;
		for(j=1;j<=m;j++)
		{
			if(a[i][j]<min[i])
			min[i]=a[i][j];
		}
		if("min[i]>max")
		max=min[i];
	}
	printf(" Gia tri de bai yeu cau la %f",max);
	getch();
}
