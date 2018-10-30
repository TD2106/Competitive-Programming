#include <iostream>
#include <math.h>
using namespace std;

int giaithua(int n)
{
	if(n==0)
	return 1;
	else
	return n*giaithua(n-1);
}
int main ()

{
	int n;
	cout <<"Nhap vao so n: ";
	cin>>n;
	int a=giaithua(n),b=0;
	for (int i=1;i<=sqrt(a);i++)
	{
		if ((i-1)*i*(i+1)==a)
		{
			cout <<"Ba so can tim la: "<<i-1<<" "<<i<<" "<<i+1;
			b=1;
			break;
		}
	}
	if(b==0)
	cout<<"Ko co ba so thoa de bai"<<endl;
	return 0;
}
