// In ngu
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
//#define read(x) freopen(x,"r",stdin)
using namespace std;
int main ()
{
	int testcase,coin,time;
	//read("test.txt");
	scanf("%d",&testcase);
	while(testcase--)
	{
		scanf("%d%d",&coin,&time);
		int array[coin+1]={0},check=0,result;	
		while(time--)
		{
			char test;
			int temporary;
			scanf("%d",&temporary);
			temporary=2*temporary;
			int array2[temporary];
			for(int i=0;i<temporary;i++)
			scanf("%d",&array2[i]);
			getchar();
			scanf("%c",&test);
			getchar();
			if(test=='=')
			{
				for(int i=0;i<temporary;i++)
				array[array2[i]]=1;
			}
			else
			{
				vector<int> temp(array2,array2+temporary);
				sort(temp.begin(),temp.end());
				int j=0;
				for(int i=1;i<=coin;i++)
				{
					if(j==temp.size())
					array[i]=1;
					else
					{
						if(i==temp[j]) j++;
						else
						array[i]=1;
					}
				}
			}
		}
		for(int i=1;i<=coin;i++)
		{
			if(array[i]==0)
			{
				check++;
				result=i;
			}
		}
		if(check==1)
		printf("%d\n",result);
		else
		printf("0\n");
		if(testcase!=0)
		printf("\n");
	}
	return 0;
}
