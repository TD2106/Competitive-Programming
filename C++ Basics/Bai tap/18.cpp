#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
	int n,s=0,array[4],a;
	cout <<"Nhap so n>=1000 và <=9999 ";
	cin>>n;
	if(n<1000||n>9999)
	{
		cout<<"Nhap sai";
		exit(0);
	}
	a=n;
	for(int i=0;i<4;i++)
	{
		array[i]=a%10;
		a=a/10;
	}
	for(int i=0;i<4;i++)
	{
		s=s+array[i]*pow(10,3-i);
	}
	if(s==n)
	cout<<"n la so co cac chu so doi xung"<<endl;
	else
	cout<<"n ko co cac chu so doi xung"<<endl;
	for(int i=0;i<4;i++)
	{
		a=0;
		for(int j=0;j<4;j++)
		{
			if(array[i]==array[j])
			a=a+1;
		}
		if(a>=3)
		{
			cout<<"Co 3 so giong nhau"<<endl;
			break;
		}
	}
	if(a<3)
	cout<<"Ko co 3 so giong nhau"<<endl;
	for(int i=0;i<4;i++)
	{
		a=0;
		for(int j=0;j<4;j++)
		{
			if(array[i]==array[j])
			a=a+1;
		}
		if(a==4)
		{
			cout<<"Co 4 so giong nhau"<<endl;
			break;
		}
	}
	if(a!=4)
	cout<<"Ko co 4 so giong nhau"<<endl;
	return 0;
}
