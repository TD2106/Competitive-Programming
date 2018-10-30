#include <iostream>
using namespace std;
int main ()
{
	int create[12],need[12],initial,total[12],count=1;
	while(1)
	{
		cin>>initial;
		if(initial<0)
		break;
		for(int i=0;i<12;i++)
		cin>>create[i];
		for(int i=0;i<12;i++)
		cin>>need[i];
		for(int i=0;i<12;i++)
		{
			if(i==0)
			total[i]=initial;
			else
			{
				int check=total[i-1]-need[i-1];
				if(check>=0)
				total[i]=check+create[i-1];
				else
				total[i]=total[i-1]+create[i-1];
			}
		}
		cout<<"Case "<<count<<":"<<endl;
		count++;
		for(int i=0;i<12;i++)
		{
			if(total[i]>=need[i])
			cout<<"No problem! :D"<<endl;
			else
			cout<<"No problem. :("<<endl;
		}
	}
	return 0;
}
