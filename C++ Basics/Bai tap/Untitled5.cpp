#include <iostream>
#include <math.h>
#include <conio.h>
int main ()
{
	int i,j,n,s=0;
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
	for(i=0;i<n;i++)
	{
		s=s+a[i][i];
	}
	printf("Tong cac so tren duong cheo chinh la %d\n",s);
	s=0;
	int k,b,c;
	for(i=0;i<n;i++)
	{
		k=0;
		for(j=i+1;j<n;j++)
		{
			for(c=i+1;c<n;c++)
			{
				for(b=0;b<i;b++)
				if(a[i][j]<a[c][b])
				{
					k=1;
				}
			}
			if(k==0)
			s=s+a[i][j];
			
		}
	}
	if(s!=0)
	printf("Tong cau b la %d ",s);
	if(s==0)
	printf("Ko ton tai so thoa cau b");
	getch();
	
}
