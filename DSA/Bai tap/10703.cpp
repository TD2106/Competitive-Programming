#include <iostream>
#include <algorithm>
using namespace std;
struct rec
{
	int row[2];
	int col[2];
};
void markarray(int array[][505],rec data)
{
	for(int i=data.col[0];i<=data.col[1];i++)
	{
		for(int j=data.row[0];j<=data.row[1];j++)
		{
			array[i][j]=1;
		}
	}
}
int count(int array[][505],int W, int H)
{
	int count=0;
	for(int i=1;i<=W;i++)
	for(int j=1;j<=H;j++)
	{
		if(!array[j][i])
		count++;
	}
	return count;
	
}
int main ()
{
	int W,H,N;
	//freopen("10703.txt","r",stdin);
	cin>>W>>H>>N;
	while(W)
	{
		int array[505][505]={0};
		while(N--)
		{
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			rec temp;
			if(x1>x2)
			{
				temp.row[0]=x2;
				temp.row[1]=x1;
			}
			else
			{
				temp.row[0]=x1;
				temp.row[1]=x2;
			}
			if(y1>y2)
			{
				temp.col[0]=y2;
				temp.col[1]=y1;
			}
			else
			{
				temp.col[0]=y1;
				temp.col[1]=y2;
			}
			markarray(array,temp);
		}
		int result=count(array,W,H);
		if(result>1)
		{
			cout<<"There are "<<result<<" empty spots.\n";
		}
		else
		{
			if(result==1)
			cout<<"There is one empty spot.\n";
			else
			cout<<"There is no empty spots.\n";
		}
		cin>>W>>H>>N;
	}
	return 0;
}
