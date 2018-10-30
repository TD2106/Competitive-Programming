#include <iostream>
using namespace std;
int main ()
{
	int catalan[11]={1,1,2,5,14,42,132,429,1430,4862,16796};
	int n;
	while(cin>>n)
	{
		cout<<catalan[n]<<"\n";
		cout<<"\n";
	}
	return 0;
}
