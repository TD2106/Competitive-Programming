#include <iostream>
using namespace std;
int power2(int i)
{
	int sum=0;
	while(i)
	{
		sum+=(i%10)*(i%10);
		i/=10;
	}
	return sum;
}
int main ()
{
	int array[101]={0};
	int total=0;
	for(int i=1;i<=100;i++)
	{
		int time=20,temp=i;
		while(time--)
		{
			temp=power2(temp);
			if(temp==1)
			{
				array[i]=1;
				break;
			}
		}
	}
	int A,B;
	cin>>A>>B;
	for(int i=A;i<=B;i++)
	{
		int temp=i;
		while(temp>100)
		{
			temp=power2(temp);
		}
		if(array[temp])
		total++;
	}
	cout<<total;
	return 0;
}
