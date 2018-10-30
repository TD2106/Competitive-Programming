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
	int b=0,c=0;
	for(int j=i-1;j>=0;j--)
	{
		array[j]=a%10;
		a=a/10;
		if(array[j]%2==0)
		b++;
		else
		c++;
	}
	b=b-1;
	c=c-1;
	for(int j=0;j<i;j++)
	{
		if(array[j]%2==0)
		{
			s1=s1+array[j]*pow(10,b);
			b--;
		}
		else
		{
			s2=s2+array[j]*pow(10,c);
			c--;
	    }
	}
	cout << s1 << " " << s2 <<endl;
	cout << s1-s2 << endl;
	return 0;
}
