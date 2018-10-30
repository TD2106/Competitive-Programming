#include <iostream>
using namespace std;
int main ()
{
	int tong1=0,tong2=0;
	for(int i=1;i<=10;i++)
	{
		tong2=0;
		for(int j=1;j<=15;j++)
		tong2=tong2+(i-j)*(i-j);
		tong1=tong1+i*i*i*tong2;
	}
	cout<<tong1;
}
