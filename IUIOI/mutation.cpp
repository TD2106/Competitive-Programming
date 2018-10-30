#include <iostream>
using namespace std;
void printarray (int arr[],int N)
{
	for(int i=1;i<N;i++)
	cout<<arr[i]<<" ";
	cout<<arr[N];
}
int main ()
{
	int N,K,temp,check=1,bol;
	cin>>N>>K;
	int output1[100005]={0},output2[100005]={0};
	for(int i=1;i<=N;i++)
	{
		cin>>temp;
		output1[temp]++;
	}
	K=K-1;
	while(K--)
	{
		bol=1;
		if(check%2)
		{
			for(int i=1;i<=N;i++)
			{
				output2[output1[i]]++;
				output1[i]=0;
				if(i>1)
				if(output2[i])
				bol=0;
			}
			check++;
			if(output2[1]!=1)
			bol=0;
			if(bol)
			break;
		}
		else
		{
			for(int i=1;i<=N;i++)
			{
				output1[output2[i]]++;
				output2[i]=0;
				if(i>1)
				if(output1[i])
				bol=0;
			}
			check++;
			if(output1[1]!=1)
			bol=0;
			if(bol)
			break;
		}
	}
	if(check%2)
	printarray(output1,N);
	else
	printarray(output2,N);
	return 0;
}
