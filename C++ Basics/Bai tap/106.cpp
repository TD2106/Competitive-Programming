#include <iostream>
using namespace std;
int main ()
{
	int cao,rong;
	cout<<"Nhap chieu cao: ";
	cin>>cao;
	cout<<"Nhap chieu rong: ";
	cin>>rong;
	for(int i=0;i<cao;i++)
	{
		for(int j=0;j<rong;j++)
		{
			if(i==cao/2)
			cout<<"* ";
			else
			{
				if(j==0||j==rong-1)
				cout<<"* ";
				else
				cout<<"  ";
			}
		}
		cout<<endl;
	}
}
