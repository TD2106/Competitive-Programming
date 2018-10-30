#include <iostream>
#include <math.h>
using namespace std;


int main ()
{
	int n,a,b,c;
	cout<<"Nhap vao so n: ";
	cin>>n;
	int array[n];
	for(int i=0;i<n;i++)
	{
		cout <<"Nhap so hang thu "<<i+1<<": ";
		cin>>array[i];
	}
	a=0;
	c=0;
	int d=0;
	for(int i=0;i<n;i++)
	{
		int e=sqrt(array[i]);
		if(e*e==array[i])
		{
			cout<<array[i]<<" la so chinh phuong" <<endl;
			a=1;
		}
		b=0;
		for(int j=2;j<array[i];j++)
		{
			if(array[i]%j==0)
			{
				b=1;
				break;
			}
		}
		if(b==0)
		{
			cout <<array[i]<<" la so nguyen to"<<endl;
			d=1;
		}
		for(int j=0;j<array[i];j++)
		{
			if(pow(5,j)==array[i])
			{
				c=1;
				cout<<array[i]<<" la luy thua cua 5"<<endl;
				break;
			}
		}
		
	}
	if(a==0)
	cout<<"Day so ko co so chinh phuong"<<endl;
	if(d==0)
	cout<<"Day so ko co so mguyen to"<<endl;
	if(c==0)
	cout<<"Day so ko co so la luy thua cua 5"<<endl;
	return 0;

	
}
