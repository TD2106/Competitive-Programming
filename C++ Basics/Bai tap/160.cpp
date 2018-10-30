#include <iostream>
#include <cmath>
using namespace std;
int coso10(int M,int i,int k)
{
	return pow(i,k)*M;
}
void doi(int j, long int s)
{
	if(s<j)
	cout<<s;
	else
    {
    	doi(j,s/j);
    	cout<<s%j;
    }
}

int main ()
{
	int i,j,M[9];
	long int s=0;
	cout<<"Nhap i va j ";
	cin>>i>>j;
	cout<<"Nhap day M"<<endl;
	for(int a=0;a<9;a++)
	{
		cin>>M[a];
		s=s+coso10(M[a],i,9-a-1);
	}
	doi(j,s);
	
	
}
