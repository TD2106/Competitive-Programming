#include <iostream>
#include <bitset>
using namespace std;
bitset<20> mark;
int arr[20],B,N;
int total(int arr[],int size)
{
	int total=0;
	for(int i=0;i<size;i++)
	if(mark[i])
	total+=arr[i];
	return total;
}
void permutation (int size, int n,int &min)
{
	if(n==0)
	{
		for(int i=0;i<2;i++)
		{
			mark[size-n-1]=i;
			int minus=total(arr,size)-B;
			if(minus>=0&&minus<min)
			min=minus;
		}
	}
	else
	{
		for(int i=0;i<2;i++)
		{
			mark[size-n-1]=i;
			permutation(size,n-1,min);
		}
	}
}

int main ()
{
	int min=1000001;
	cin>>N>>B;
	for(int i=0;i<N;i++)
	cin>>arr[i];
	permutation(N,N-1,min);
	cout<<min;
	return 0;
}
