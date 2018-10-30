#include <iostream>
using namespace std;
int main()
{
	int n,a=0;
	cout <<"Nhap so n: ";
	cin>>n;
	for (int i=0;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			for(int k=0;k<=j;k++)
			{
				if(i*i==(j*j+k*k))
				{
					a=1;
					cout <<"Bo 3 so a,b,c lan luot la: "<<i<<" "<<j<<" "<<k<<endl;
				}
				
			}
		}
	}
	if(a==0)
	cout<<"Ko co ba so thoa de bai"<<endl;
	return 0;
}
