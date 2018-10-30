#include <iostream>
using namespace std;
int check(int i)
{
	int s=0;
	for(int j=1;j<i;j++)
	{
		if(i%j==0)
		s=s+j;
	}
	if(s==i)
	return 1;
	else
	return 0;
	
}
int main ()
{
	int m;
	cout<<"Nhap m ";
	cin>>m;
	for(int i=1;i<m;i++)
	{
		if(check(i))
		cout<<i<<" la so hoan hao"<<endl;
	}
	return 0;
}
