#include <iostream>
using namespace std;
int main ()
{
	string out="far";
	int n;
	cin>>n;
	cout<<"A long time ago in a galaxy";
	for(int i=0;i<n;i++)
	{
		if(i==n-1)
		cout<<" "<<out<<" ";
		else
		cout<<" "<<out<<",";
	}
	cout<<"away...";
	return 0;
}
