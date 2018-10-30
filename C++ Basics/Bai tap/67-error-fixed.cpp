#include <iostream>
#include <math.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
int main ()
{
	int i,j,n,s=0, check=0;
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
	int k,b;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			for(int k=0; k<n-1; ++k)
			{
			    for (int h=k+1; h<n; ++h)
                {
                    if(a[i][j]>a[h][k]) check++;
                    if(check==(n*n-n)/2)
                    {
                        s+=a[i][j];
                        check=0;
                    }
                }
			}
		}
	}
	if(s!=0)
	printf("Tong cau b la %d ",s);
	if(s==0)
	printf("Ko ton tai so thoa cau b");
	getch();

}
