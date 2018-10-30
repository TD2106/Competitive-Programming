#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	float x,y;
	cin>>x>>y;
	int a=log(x)/log(y)-1,b=log(x)/log(y)+1,check=1;
	for(int i=a;i<=b;i++)
	if((pow(y,i-1)<=x&&x<pow(y,i)))
	{
		cout<<i;
		check=0;
	}
	if(check)
	cout<<"Ko co so phu hop";
	
	
}
