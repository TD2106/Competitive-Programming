#include <iostream>
using namespace std;
int x[100];
int check(int j,int i)
{
	int check=1;
	for(int k=0;k<i;k++)
	{
		if(j==x[k])
		{
			check= 0;
			break;
		}
	}
	return check;
}
void process(int i,int n,int k)
{
	int *a;
	a=&x[i];
	for(int j=1;j<=n;j++)
	{
		if(check(j,i))
		{
			*a=j;
			if(i!=k-1)
			process(i+1,n,k);
			else
			{
				for(int h=0;h<k;h++)
				cout<<x[h];
				cout<<endl;
			}
		}
		
	}
}
int main ()
{
	process(0,5,4);
}
