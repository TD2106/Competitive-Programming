#include <iostream>
#include <algorithm>
using namespace std;
bool check=0;
int row,column,desrow,descol,cnt=0;
void dequy (char table[52][52],int currow,int curcol,int nextrow,int nextcol)
{
	table[currow][curcol]='.';
	for(int i=1;i<=row;i++)
	{
		for(int j=1;j<=column;j++)
		{
			if(table[i][j]=='*')
			{
				if(table[i+1][j]=='.')
				table[i+1][j]='*';
				if(table[i][j+1]=='.')
				table[i][j+1]='*';
				if(table[i+1][j]=='.')
				table[i+1][j]='*';
				if(table[i+1][j]=='.')
				table[i+1][j]='*';
			}
		}
	}
	
}
