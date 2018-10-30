#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;
int main ()
{
	int n,y,a,b,j,hieu,count=1;
	//freopen("700.txt","r",stdin);
	cin>>n;
	while(n)
	{
		bitset<10001> result;
		for(int i=0;i<n;i++)
		{
			cin>>y>>a>>b;
			hieu=b-a;
			j=0;
			if(i==0)
			{
				while(y+hieu*j<10000)
				{
					result[y+hieu*j]=1;
					j++;
				}
			}
			else
			{
				bitset<10001> temp;
				while(y+hieu*j<10000)
				{
					temp[y+hieu*j]=1;
					j++;
				}
				result&=temp;
			}
		}
		cout<<"Case #"<<count<<":\n";
		if(result.count())
		{
			for(int i=0;i<10000;i++)
			if(result[i])
			{
				cout<<"The actual year is "<<i<<".\n";
				break;
			}
		}
		else
		cout<<"Unknown bugs detected.\n";
		count++;
		cout<<"\n";
		cin>>n;
	}
	return 0;
}
