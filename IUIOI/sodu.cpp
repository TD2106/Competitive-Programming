#include <iostream>
using namespace std;
int main ()
{
	int checkmodulo[42]={0};
	int temp,count=0;
	for(int i=0;i<10;i++)
	{
		cin>>temp;
		if(checkmodulo[temp%42]==0)
		{
			count++;
			checkmodulo[temp%42]=1;
		}
	}
	cout<<count;
	return 0;
}
