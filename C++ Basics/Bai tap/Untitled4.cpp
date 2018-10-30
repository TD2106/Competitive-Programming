#include <iostream>
#include <math.h>
#include <conio.h>
int main ()
{
	int i,j,n;
	printf(" Nhap so n vao ");
	scanf("%d",&n);
	printf(" Nhap so i vao ");
	scanf("%d",&i);
	printf(" Nhap so j vao ");
	scanf("%d",&j);
	int a,b,c,d,e;
	int array1[n][n];
	c=n-1;
	int array2[c][c];
	for (a=0;a<n;a++)
	{
		for(b=0;b<n;b++)
		{
			printf("Nhap vao so array1[%d][%d] ",a,b);
			scanf("%d",&array1[a][b]);
			
		}
	}
	
	
	d=0;
	for(a=0;a<c;a++)
	{
		if(d==i)
		d=d+1;
		e=0;
		for(b=0;b<n;b++)
		{
			
			if(e==j)
			e=e+1;
			array2[a][b]=array1[d][e];
			e++;
		}
		d++;
	}
	
	
	
	
	for(a=0;a<c;a++)
	{
		for(b=0;b<c;b++)
		printf(" %d ",array2[a][b]);
		printf("\n");
	}
	
	getch();
	
}

