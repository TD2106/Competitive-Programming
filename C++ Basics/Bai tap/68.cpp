#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>

using namespace std;


int main ()
{
	int n,i,j;
	printf("Nhap vao so n ");
	scanf("%d",&n);
	cin.ignore(); 
	char a[n][n];
	for (i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf(" Nhap vao ki tu a[%d][%d] ",i,j);
			scanf("%c",&a[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		a[i][i]='a';
	}
	for (i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf(" %c ",a[i][j]);
			
		}
		printf("\n");
	}
	getch();
	
}
