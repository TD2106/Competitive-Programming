#include <iostream>
using namespace std;
int tinh(int n)
{
	if(n==0)
	return 1;
	else
	return n*tinh(n-1)+1;
}
int main ()
{
	int n;
	cin>>n;
	cout<<tinh(n);
	return 0;
}
