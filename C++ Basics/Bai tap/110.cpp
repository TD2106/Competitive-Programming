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
			int b=a/2+i,c=a/2-i;
			if(j>=c&&j<=b)
			cout<<"* ";
			else
			cout<<"  ";
		}
		cout<<endl;
	}
}
