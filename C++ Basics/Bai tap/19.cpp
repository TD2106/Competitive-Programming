#include <iostream>
using namespace std;
int main ()
{
	int m,n;
	cout<<"Nhap gio ";
	cin>>m;
	cout<<"Nhap phut ";
	cin>>n;
	// Câu a
	float a=(m*1.0)/12.0+(n*1.0)/(12.0*60.0),b=(n*1.0)/60.0,c=(1.0/60.0)-(1.0/(60.0*24.0));
	if(a<b)
	b=b-1.0;
	cout <<"Hai kim trung nhau sau "<<(a-b)/c<<" phut"<<endl;
	// Câu b
	a=(m*1.0)/12.0+(n*1.0)/(12.0*60.0),b=(n*1.0)/60.0,c=(1.0/60.0)-(1.0/(60.0*24.0));
	if(a>b)
	{
		if((a-b)<0.25)
		{
			cout<<"Hai kim vuong goc sau "<<(0.25+a-b)/c<<" phut";
		}
		else
		{
			cout<<"Hai kim vuong goc sau "<<(0.25-a+b)/(c*(-1.0))<<" phut";
		}
	}
	if(a<b)
	{
		if((b-a)>0.25)
		{
			b=b-1.0;
			cout<<"Hai kim vuong goc sau "<<(0.25-a+b)/(c*(-1.0))<<" phut";
		}
		if((b-a)<0.25)
		{
			cout<<"Hai kim vuong goc sau "<<(0.25+a-b)/c<<" phut";
		}
	}
	return 0;
}
