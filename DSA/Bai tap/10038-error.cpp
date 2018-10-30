#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n) == 1)
	{
		int check[n]={0},dem=n-1,var1,var2,temp,test=1;
		scanf("%d",&var1);
		for(int i=1;i<n;i++)
		{
			scanf("%d",&var2);
			if(var1<=0||var2<=0)
			{
				printf("Not jolly\n");
				test=0;
				break;
			}
			temp=var2-var1;
			if(temp<0)
			temp=temp*(-1);
			if(temp<1||temp>n-1)
			{
				printf("Not jolly\n");
				test=1;
				break;
			}
			else
			{
				if(check[temp]==0)
				{
					check[temp]++;
					dem--;
				}
				else
				{
					printf("Not jolly\n");
					test=0;
					break;
				}
			}
		}
		if(test==1&&dem==0)
		printf("Jolly\n");
	}
	return 0;
}
