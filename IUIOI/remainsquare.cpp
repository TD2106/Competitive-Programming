#include <iostream>
using namespace std;
bool table[105][105]={0};
void spread(int row, int column)
{
	if(!table[row][column])
	return ;
	else
	{
		table[row][column]=0;
		spread(row+1,column);
		spread(row-1,column);
		spread(row,column+1);
		spread(row,column-1);
	}
}
int main ()
{
	char temp;
	int m,n,cnt=0;
	cin>>m>>n;
	cin.ignore();
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>temp;
			if(temp=='#')
			table[i][j]=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(table[i][j])
			{
				cnt++;
				spread(i,j);
			}
		}
	}
	cout<<cnt;
	return 0;
}
