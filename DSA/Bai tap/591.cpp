#include <iostream>
using namespace std;
int main()
{
	int n,dem=0,avg,gach;
	long int sum;
	cin>>n;
	while(n)
	{
		dem++;
		sum=0;
		gach=0;
		int mang[n];
		for(int i=0;i<n;i++)
		{
			cin>>mang[i];
			sum=sum+mang[i];
		}
		avg=sum/n;
		for(int i=0;i<n;i++)
		{
			if(mang[i]>avg)
			gach=gach+mang[i]-avg;
		}
		cout<<"Set #"<<dem<<endl<<"The minimum number of moves is "<<gach<<"."<<endl<<endl;
		cin>>n;
	}
}
