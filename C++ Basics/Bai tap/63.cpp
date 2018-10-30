#include <iostream>
#include <math.h>
#include <conio.h>
int main ()
{
	int m,n;
	printf("Nhap vao so m ");
	scanf("%d",&m);
	printf("Nhap vao so n ");
	scanf("%d",&n);
	float a[m+1][n+1];
	int i,j;
	float b[m+1],c[m+1],max,min,s,k;
	for (i=1;i<=m;i++)
	{
		for (j=1;j<=n;j++)
		{
			printf("Nhap vao so a[%d][%d] ",i,j);
			scanf("%f",&a[i][j]);
		}
	}
	for (i=1;i<=m;i++)
	{
		s=0.0;
		k=0.0;
		b[i]=0.0;
		c[i]=1.0;
		max=-100.0;
		min=100.0;
		for (j=1;j<=n;j++)
		{
			b[i]=b[i]+a[i][j];
			c[i]=c[i]*a[i][j];
			if(a[i][j]<min)
			min=a[i][j];
			if(a[i][j]>max)
			max=a[i][j];
			if(a[i][j]>0)
			s=s+a[i][j];
			if(a[i][j]>=1.0&&a[i][j]<=15.0)
			k=k+a[i][j];
				
		}
		printf("Tong cua hang %d la %f\n",i,b[i]);
		printf("Tich cua hang %d la %f\n",i,c[i]);
		printf("So be nhat cua hang %d la %f\n",i,min);
		printf("So lon nhat cua hang %d la %f\n",i,max);
		printf("Tong gia tri so be nhat cua hang %d la %f\n",i,min+max);
		printf("Tong gia tri cac so duong cua hang %d la %f\n",i,s);
		printf("Tong gia tri cac so thuoc khoang gia tri [1;15] cua hang %d la %f\n",i,k);
	}
	getch();
}

	
	

