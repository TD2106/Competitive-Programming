#include <iostream>
#include <bitset>
using namespace std;
int main ()
{
	int n,temp,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		if(!temp)
		cnt++;
	}
	if(cnt==1)
	cout<<"YES";
	else
	cout<<"NO";
	return 0;
}
