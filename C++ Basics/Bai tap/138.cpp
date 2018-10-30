#include <iostream>
using namespace std;
int check(int n)
{
	int a[4],b=1;
	for(int i=0;i<4;i++)
	{
		a[i]=n%10;
		n=n/10;
	}
	for(int i=0;i<3;i++)
	{
		for(int j=i+1;j<4;j++)
		{
			if(a[i]==a[j])
			{
				b=0;
				break;
			}
		}
	}
	return b;
}
int main()
{
	for(int i=1000;i<9999;i++)
	{
		if(check(i))
		cout<<i<<" co 4 chu so doi mot khac nhau"<<endl;
	}
	return 0;
}
