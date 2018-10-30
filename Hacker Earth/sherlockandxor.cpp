#include <iostream>
#include <bitset>
using namespace std;
int main ()
{
	int testcase,temp,n;
	bitset<100001> mark;
	cin>>testcase;
	while(testcase--)
	{
		int arr[100001],n,sumeven=0,sumodd=0;
		long long total=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			if(temp%2)
			{
				arr[i]=sumeven;
				sumodd++;
				mark[i]=1;
			}
			else
			{
				sumeven++;
				arr[i]=sumodd;
				mark[i]=0;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(mark[i])
			{
				total+=sumeven-arr[i];
			}
			else
			{
				total+=sumodd-arr[i];
			}
		}
		cout<<total<<"\n";
		mark.reset();
	}
	return 0;
}
