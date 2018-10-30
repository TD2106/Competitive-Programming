#include <iostream>
#include<conio.h>
int main()
{
	int i,j,k,m,s=0;
	int a[21];
	printf("Nhap vao so m ");
	scanf("%d",&m);
	for(i=1;i<21;i++)
	{
		printf(" Nhap vao so a[%d]: ",i);
		scanf("%d",&a[i]);
		
	}
	for(i=1;i<=20;i++)
	{
		for(j=1;j<=(20-i);j++)
		{
			for(k=1;k<=(20-i-j);k++)
			{
			if(((a[i]+a[j]+a[k])==m)&&((i+j+k)<20))
			{
			
			s=1;
			printf("Bo ba 3 so la %d %d %d \n",i,j,k);
		    }
		    }
		}
	}
	if(s==0)
	{
		printf("Ko ton tai 3 so thoa de bai");
		
	}
	getch();
}
