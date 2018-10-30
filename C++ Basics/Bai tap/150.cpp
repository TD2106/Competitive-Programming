#include <iostream>
using namespace std;
int main ()
{
	float a[15]={0.3,2.0,0,9.4,5.2,0,6.9,7.5,9.7,0,12.3,14.5,0.4,19,0};
	for(int i=0;i<15;i++)
	{
		if(a[i]!=0)
		cout<<"So a["<<i<<"]: "<<a[i]<<endl;
	}
	for(int i=0;i<15;i++)
	{
		if(a[i]==0)
		cout<<"So a["<<i<<"]: "<<a[i]<<endl;
	}
}
