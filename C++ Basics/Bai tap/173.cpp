#include <iostream>
using namespace std;
int main ()
{
	int n,s,nam=0;
	cin>>n;
	s=9870;
	while(1)
	{
		s=s+s*0.1;
		nam++;
		if(s>n)
		break;
	}
	cout<<nam<<endl;
	return 0;
}
