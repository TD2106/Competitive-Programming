#include <iostream>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	float s=1;
	for(int i=1;i<=n;i++)
	{
		int a=i*i+i+1;
		s=s+1.0/(a*1.0);
		cout<<"f["<<i<<"]: "<<s<<endl;
	}
	return 0;
}
