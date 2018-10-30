#include <iostream>
using namespace std;
int main ()
{
	unsigned int input[500000];
	long long total=0;
	int n;
	cin>>n;
	total=0;
	for(int i=0;i<n;i++)
	cin>>input[i];
	for(int i=0;i<n-1;i++)
	{
		int max=0;
		for(int j=i+1;j<n;j++)
		{
			if(input[j]>=max)
			{
				total++;
				max=input[j];
			}
			if(max>input[i])
			break;
		}
	}
	cout<<total;
	return 0;
}
