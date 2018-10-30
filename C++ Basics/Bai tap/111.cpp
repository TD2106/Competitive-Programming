#include <iostream>
using namespace std;
int main ()
{
	int n;
	cout<<"Nhap so n: ";
	cin>>n;
	int a=1+2*(n-1);
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<a;j++)
		{
			int b=i,c=a-i-1;
			if(j>=b&&j<=c)
			cout<<"* ";
			else
			cout<<"  ";
		}
		cout<<endl;
	}
}
