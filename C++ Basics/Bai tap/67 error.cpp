#include <iostream>
#include <math.h>
#include <conio.h>
int main ()
{
	int i,j,n,s=0,k=0;
	printf("Nhap vao so n ");
	scanf("%d",&n);
	int a[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		printf("Nhap so a[%d][%d] ",i,j);
		scanf("%d",&a[i][j]);
	    }
	}
	int max=0;
	for (i=0;i<n;i++)
	{
		for (j=i-1;j>=0;j--)
		{
			if(a[i][j]>max)
			max=a[i][j];
		}
		
	}
	for (i=0;i<n;i++)
	{
		if (a[i][i]>max)
		s=s+a[i][i];
		for(j=i+1;j<n;j++)
		{
			if(a[i][j]>max)
			k=k+a[i][j];
		}
	}
	printf(" Tong cua cau a %d",s);
	printf(" Tong cua cau b %d",k);
	getch();
	
}
