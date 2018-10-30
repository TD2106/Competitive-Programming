#include <iostream>
#include <math.h>
#include <conio.h>
int main ()
{
	int n,i,j;
	printf("Nhap vao so n: ");
	scanf("%d",&n);
	float a[n+1][n+1];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			a[i][j]=1.0/((1.0*i)+(1.0*j));
			printf(" %f ",a[i][j]);
			
		}
		printf("\n");
		
	}
	getch();
	
}
