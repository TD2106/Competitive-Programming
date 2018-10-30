#include <iostream>
using namespace std;
int main ()
{
	string s1,s2,temp;
	int n,sum1=0,sum2=0;
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			cin>>s1;
			sum1++;
		}
		else
		{
			cin>>temp;
			if(temp!=s1)
			{
				s2=temp;
				sum2++;
			}
			else
			sum1++;
		}
	}
	if(sum1>sum2)
	cout<<s1;
	else
	cout<<s2;
	return 0;
}
