#include <iostream>
using namespace std;
int main ()
{
	int m,n,max,min;
	long long int tich,tong;
	while(cin>>m>>n)
	{
		tich=1;
		tong=0;
		if(m>n)
		{
			max=m;
			min=n;
		}
		else
		{
			max=n;
			min=m;
		}
		if(max==0)
		cout<<"2\n";
		else
		{
			if(min==0&&max>0)
			tong=tong+1;
			for(int i=1;i<=max;i++)
			{
				tich*=i;
				if(i==min)
				tong=tong+tich;
			}
			tong=tong+tich;
			cout<<tong<<"\n";
		}
	}
	return 0;
}
