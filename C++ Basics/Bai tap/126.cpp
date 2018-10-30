#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<int> snt;
	cout<<"Nhap so n: ";
	cin>>n;
	int s=0,i,d=7,e=1;
	while(s!=n)
	{
		i=30*e;
		for(int j=d;j<i;j++)
		{
			int b=0;
			for(int k=2;k<=sqrt(j);k++)
			{
				if(j%k==0)
			    {
			    	b=1;
			    	break;
				}
			}
			if(b==0)
			snt.push_back(j);
		}
		int c=0;
		for(int j=0;j<snt.size();j++)
		{
			if(i%snt[j]==0)
			{
				c=1;
				break;
			}
		}
		if(c==0&&i%2==0&&i%3==0&&i%5==0)
		{
			cout<<i<<" ";
			s++;
		}
		d=i;
		e++;	
	}
	return 0;
}
