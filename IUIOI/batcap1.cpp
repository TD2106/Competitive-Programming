#include <iostream>
#include <cstdlib>
using namespace std;
int main ()
{
	int N;
	unsigned **arr,max;
	long long *mark;
	cin>>N;
	mark=(long long*)malloc(N*sizeof(long long));
	arr=(unsigned**)malloc(2*sizeof(unsigned*));
	for(int i=0;i<2;i++)
	arr[i]=(unsigned*)malloc(N*sizeof(unsigned));
	long long total=0;
	for(int i=0;i<N;i++)
	{
		cin>>arr[0][i];
		if(i==0)
		{
			arr[1][0]=0;
			mark[0]=0;
		}
		else if(i==1)
		{
			if(arr[0][0]>=arr[0][1])
			mark[1]=1;
			else
			mark[1]=0;
			arr[1][i]=1;
		}
		else
		{
			arr[1][i]=1;
			mark[i]=0;
		}
		if(i>=2)
		{
			max=arr[0][i-1];
			if(max==arr[0][i])
			{
				mark[i]+=1+mark[i-1];
				total+=mark[i];
				continue;
			}
			if(max>arr[0][i])
			{
				mark[i]++;
				total++;
				continue;
			}
		}
		for(int j=i-2;j>=0;j--)
		{
			if(arr[0][j]==arr[0][i])
			{
				arr[1][i]+=1+mark[j];
				mark[i]+=1+mark[j];
				break;
			}
			if(arr[0][j]>=max)
			{
				max=arr[0][j];
				arr[1][i]++;
				if(arr[0][j]>arr[0][i])
				{
					mark[i]++;
					break;
				}
			}
		}
		total+=arr[1][i];
	}
	/*for(int i=0;i<N;i++)
	cout<<arr[0][i]<<"\t";
	cout<<endl;
	for(int i=0;i<N;i++)
	cout<<arr[1][i]<<"\t";
	cout<<endl;
	for(int i=0;i<N;i++)
	cout<<mark[i]<<"\t";
	cout<<endl;*/
	cout<<total;
	return 0;
}
