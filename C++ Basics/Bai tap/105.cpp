#include <iostream>
using namespace std;
int main ()
{
	int rong,cao;
	cout << "Nhap vap chieu rong ";
	cin>>rong;
	cout<< "Nhap vao chieu cao ";
	cin>>cao;
	for(int i=0;i<cao;i++)
	{
		for(int j=0;j<rong;j++)
		{
			if(i==0||i==cao/2)
			cout<<"* ";
			else
			{
				if(j==0)
				cout<<"*";
			}
		}
		cout<<endl;
	}
}
