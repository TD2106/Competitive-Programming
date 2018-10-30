#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int testcase,x;
	unsigned long long tich,tong,kg;
	cin>>testcase;
	while(testcase--)
	{
		kg=0;
		cin>>x;
		if(x<=13)
		cout<<"0 kg\n";
		if(x==14)
		cout<<"1 kg\n";
		if(x>14)
		{
			tich=16384;
			kg=1;
			tong=16383-12000;
			for(int i=15;i<=x;i++)
			{
				tong=tong+tich;
				kg=kg+tong/12000;
				tong=tong%12000;
				tich=tich*2;
			}
			cout<<kg<<" kg\n";
		}
	}
	return 0;
}
