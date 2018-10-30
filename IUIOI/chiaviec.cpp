#include <iostream>
#include <cstdio>
using namespace std;
double ans=1.000000,input[21][21]={0},mx=0.000000;
bool ques[21]={0};
void test(int per,int size)
{
	for(int i=0;i<size;i++)
	{
		if(per==0)
		ans=1.000000;
		if(!ques[i])
		{
			if(ans*input[per][i]<=mx)
			continue;
			else
			{
				ans*=input[per][i]*1.000000;
				ques[i]=1;
				if(per==(size-1)&&ans>mx) mx=ans;
				if(per<size-1) test(per+1,size);
				ans/=input[per][i]*1.000000;
				ques[i]=0;
			}
		}
	}
}
int main ()
{
	int n,temp;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>temp;
			double a=(double)temp;
			a/=100.000000;
			input[i][j]=a;
		}
	}
	test(0,n);
	printf("%.6llf",mx*100.000000);
	return 0;
}
