#include <iostream>
#include <bitset>
using namespace std;
int main ()
{
	int t,e,cnt;
	bitset<10001> mark;
	cin>>t;
	while(t--)
	{
		cnt=0;
		cin>>e;
		while(e--)
		{
			int temp1,temp2;
			cin>>temp1>>temp2;
			if(!mark[temp1])
			{
				cnt++;
				mark[temp1]=1;
			}
			if(!mark[temp2])
			{
				cnt++;
				mark[temp2]=1;
			}
		}
		cout<<cnt<<endl;
		mark.reset();
	}
	return 0;
}
