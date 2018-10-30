#include <iostream>
#include <fstream>
using namespace std;
int main ()
{
	freopen("82.txt","r",stdin);
	int x,s=0,p=1;
	while (cin >> x)
	{
		s=s+x;
		p=p*x;
		
	}
	cout << s <<"\n" << p;
	return 0;
}
