#include <iostream>
using namespace std;
int main ()
{
	int input[101]={0},n,max=0,sum=0,maxsum=-1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>input[i];
		if(input[i])
		{
			max++;
			if(sum>0)
			sum--;
		}
		else
		{
			sum++;
			if(sum>maxsum)
			maxsum=sum;
		}
	}
	cout<<max+maxsum;
	return 0;
}
