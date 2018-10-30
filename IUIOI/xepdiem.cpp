#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int N,W,H,C,L;
	cin>>N>>W>>H;
	C=int(sqrt(W*W+H*H));
	while(N--)
	{
		cin>>L;
		if(L<=C)
		cout<<"DA\n";
		else
		cout<<"NE\n";
	}
	return 0;
}
