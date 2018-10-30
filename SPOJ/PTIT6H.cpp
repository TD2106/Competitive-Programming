#include <iostream>
using namespace std;
bool table[55][55]={0};
char temp;
int R,S,x,y,mx=0,cnt=0;
void count()
{
	for(int i=1;i<=R;i++)
	{
		for(int j=1;j<=S;j++)
		{
			if(table[i][j])
			{
				if(table[i+1][j])
				cnt++;
				if(table[i-1][j])
				cnt++;
				if(table[i][j-1])
				cnt++;
				if(table[i][j+1])
				cnt++;
				if(table[i+1][j+1])
				cnt++;
				if(table[i-1][j+1])
				cnt++;
				if(table[i-1][j-1])
				cnt++;
				if(table[i+1][j-1])
				cnt++;
			}
			table[i][j]=0;
		}
	}
}
void findmax()
{
	for(int i=1;i<=R;i++)
	{
		for(int j=1;j<=S;j++)
		{
			int dem=0;
			if(!table[i][j])
			{
				if(table[i+1][j])
				dem++;
				if(table[i-1][j])
				dem++;
				if(table[i][j-1])
				dem++;
				if(table[i][j+1])
				dem++;
				if(table[i+1][j+1])
				dem++;
				if(table[i-1][j+1])
				dem++;
				if(table[i-1][j-1])
				dem++;
				if(table[i+1][j-1])
				dem++;
			}
			if(dem>=mx)
			{
				x=i;
				y=j;
				mx=dem;
			}
		}
	}
}
int main ()
{
	cin>>R>>S;
	cin.ignore();
	for(int i=1;i<=R;i++)
	{
		for(int j=1;j<=S;j++)
		{
			cin>>temp;
			if(temp=='o')
			{
				table[i][j]=1;
				cnt++;
			}
		}
	}
	if(cnt==R*S)
	{
		cnt=0;
		count();
	}
	else
	{
		cnt=0;
		findmax();
		table[x][y]=1;
		count();
	}
	cout<<cnt;
}
