#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n,i,a,s1=0,s2=0;
	cout<<"Nhap so n vao: ";
	cin>>n;
	a=n;
	while (a!=0)
	{
		a=a/10;
		i++;
	}
	int array[i];
	a=n;
	for(int j=i-1;j>=0;j--)
	{
		array[j]=a%10;
		a=a/10;
	}
	if(i%2==1)
	{
		int j=0;
		a=i/2;
		while(j<i)
		{
			s1=s1+array[j]*pow(10,a);
			a--;
			j=j+2;
		}
		j=1;
		a=i/2-1;
		while(j<i)
		{
			s2=s2+array[j]*pow(10,a);
			a--;
			j=j+2;
		}
	}
	else
	{
		a=i/2-1;
		int j=0,k=1;
		while(j<i)
		{
			s1=s1+array[j]*pow(10,a);
			s2=s2+array[k]*pow(10,a);
			a--;
			j=j+2;
			k=k+2;
		}
	}
	cout << s1 << " " << s2 <<endl;
	cout << s1+s2 << endl;
}
