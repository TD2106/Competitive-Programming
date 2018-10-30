#include <iostream>
using namespace std;
int check(int i,int n)
{
	int s=0;
	while(i>0)
	{
		s=s+i%10;
		i=i/10;
	}
	if(s==n)
	return 1;
	else
	return 0;
	
}
int main ()
{
	int n;
	cout<<"Nhap so n < 27 ";
	cin>>n;
	int a=1;
	for(int i=100;i<999;i++)
	{
		if(check(i,n))
		{
			a=0;
			cout <<i<<" co tong cac chu so bang "<<n<<endl;
			
		}
	}
	if(a)
	cout<<"Ko co so nao co tong cac chu so bang "<<n<<endl;
	return 0;
}
