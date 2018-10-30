#include <iostream>
using namespace std;
int main ()
{
	int n;
	cout << " Nhap n vao " <<endl;
	cin >>n;
	for (int j=0;j<n;j++)
	{
		for (int i=0;i<n;i++)
		{
			if(j==0||j==n/2||j==n-1)
			cout << "* ";
			else
			{
				if(i==0||i==n-1)
				cout<<"* ";
				else
				cout<<"  ";
			}
		}
		cout << endl;
	}
}
