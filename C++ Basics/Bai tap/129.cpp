#include <iostream>

using namespace std;

int main ()
{
	int tien[7]={1,2,5,10,20,25,50};
	int n;
	cout<<"Nhap so tien n vao: ";
	cin>>n;
	cout<<"Dung ";
	for(int j=6;j>=0;j--)
	{
		int a=n/tien[j];
		if(tien[j]*a!=0)
		{
			cout<<a<<" to tien "<<tien[j]<<" ";
			n=n-tien[j]*a;
		}
		if(n==0)
		exit(0);
	}
	
}
