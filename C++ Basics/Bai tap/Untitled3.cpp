#include <iostream>
using namespace std;
void check (int n)
{
	if(n>0)
	{
		cout <<n<<endl;
		check(n/2);
	}
	cout<<n+1<<endl;
}
int main()
{
	int n=100;
	check(n);
}
