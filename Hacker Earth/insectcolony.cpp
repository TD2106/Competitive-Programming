#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int main ()
{
	// equal number xor each other = 0 so if num is even it split into two equal part and xor to 0 for odd. 
	// Odd xor Odd = even => solve
	int tc,n,odd,temp;
	cin>>tc;
	while(tc--)
	{
		odd=0;
		cin>>n;
		while(n--)
		{
			cin>>temp;
			if(temp%2)
			odd++;
		}
		if(odd%2)
		cout<<"No\n";
		else
		cout<<"Yes\n";
	}
	return 0;
}
