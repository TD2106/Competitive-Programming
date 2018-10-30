#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
	int n,pa[10],va[10];
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>va[i];
	for(int i=0;i<n;i++)
	cin>>pa[i];
	sort(va,va+n);
	sort(pa,pa+n);
	bool check=1;
	for(int i=0;i<n;i++)
	{
		if(pa[i]>va[i])
		{
			cout<<"No";
			check=0;
			break;
		}
	}
	if(check)
	cout<<"Yes";
	return 0;
}

