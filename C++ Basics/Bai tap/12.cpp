#include <iostream>
using namespace std;
int main ()
{
	int n;
	float a,d;
	cout <<"Nhap n";
	cin>>n;
	cout<<"Nhap a va cong sai d ";
	cin>>a>>d;
	float s=0;
	for(int i=0;i<n;i++)
	{
		s=s+a+i*d;
	}
	cout <<"Ket qua la "<<s<<endl;
	return 0;
	
}
