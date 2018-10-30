#include <cstring>
#include <cstdio>
using namespace std;
int main ()
{
	freopen("input","r",stdin);
	//freopen("out.txt","w",stdout);
	int tc,row,column;
	scanf("%d",&tc);
	while(tc--)
	{
		char table[105][105]={0};
		int arr[6]={0};
		scanf("%d %d",&row,&column);
		for(int i=1;i<=row;i++)
		{
			for(int j=1;j<=column;j++)
			scanf(" %c",&table[i][j]);
		}
		bool check=0;
		for(int i=1;i<=row;i++)
		{
			for(int j=1;j<=column;j++)
			{
				if(table[i][j]==table[i][j+1]&&table[i][j]==table[i][j+2])
				{
				//	printf("%d %d\n",i,j);
				//	printf("%d %d %d %d %d %d\n",i,j,i,j+1,i,j+2);
					arr[0]=i,arr[1]=j,arr[2]=i,arr[3]=j+1,arr[5]=j+2,arr[4]=i;
					check=1;
				//	break;
				}
			}
			//if(check)
			//break;
		}
		for(int i=1;i<=column;i++)
		{
			for(int j=1;j<=row;j++)
			{
				if(table[j][i]==table[j+1][i]&&table[j][i]==table[j+2][i])
				{
					//printf("%d %d %d %d %d %d\n",j,i,j+1,i,j+2,i);
					arr[0]=j,arr[1]=i,arr[2]=j+1,arr[3]=i,arr[4]=j+2,arr[5]=i;
					check=1;
					//break;
				}
			}
			//if(check)
			//break;
		}
		//if(check)
		//continue;
		if(!check)
		printf("no set found\n");
		else
		printf("%d %d %d %d %d %d\n",arr[0],arr[1],arr[2],arr[3],arr[4],arr[5]);
	}
	return 0;
}
