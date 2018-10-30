#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n;
int main()
{
	ios_base::sync_with_stdio(0);
	freopen("MAGICAL3.INP","r",stdin);
	freopen("MAGICAL3.OUT","w",stdout);
	while (cin >> n and n!=0)
	{
		n-=3;
		if (n==0)
			{
				cout << 4 << '\n';
			}
		else
		if (n<4)
		{
			cout << "No such base\n";
		}
		else
		{
			bool f=false;
			for (int i=4; i<=sqrt(n)+1; i++)
				if (n%i==0)
				{
					cout << i << '\n';
					f=true;
					break;
				}
			if (f) continue;
			if (n%3==0 and n/3>=4)
				cout << n/3 << '\n';
			else
			if (n%2==0 and n/2>=4)
				cout << n/2 << '\n';
			else
				cout << n << '\n';
		}
	}
	return 0;
}
