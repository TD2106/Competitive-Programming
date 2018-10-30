#include <iostream>
using namespace std;
int main ()
{
	int n;
	cin>>n;
	int s=0,temp;
	for(int i=1;i<=n;i++)
	{
		cout<<"Nhap so a["<<i<<"]: ";
		cin>>temp;
		if(temp%5==0&&temp%7!=0)
		s=s+temp;
	}
	cout<<s;
	
}
