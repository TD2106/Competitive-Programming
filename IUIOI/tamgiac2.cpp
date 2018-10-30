#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;
int main ()
{
	bool check;
	bitset<2000001> mark;
	mark[2]=mark[3]=1;
	for(int i=5;i<=2000000;i+=2)
	{
		check=1;
		if(i%2==0||i%3==0)
		continue;
		else
		{
			for(int j=6;j-1<=sqrt(i);j+=6)
			{
				if(i%(j+1)==0||i%(j-1)==0)
				{
					check=0;
					break;
				}
			}
			mark[i]=check;
		}
	}
	for(int i=1;i<=100;i++)
	{
		if(mark[i])
		cout<<i<<" ";
	}
	return 0;
}
