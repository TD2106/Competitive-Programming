#include <iostream>
#include <string>
using namespace std;
int main ()
{
	char string[201];
	int i=0,max=0,arr[201]={0},big;
	while(cin>>string[i])
	{
		big=0;
		for(int j=0;j<i;j++)
		{
			if(arr[j]>big&&string[j]<=string[i])
			big=arr[j];
		}
		arr[i]=1+big;
		if(arr[i]>max)
		max=arr[i];
		i++;
	}
	cout<<max;
	return 0;
}
