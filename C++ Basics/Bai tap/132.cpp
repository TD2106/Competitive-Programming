#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main ()
{
	double a=pow(2,200),e;
	float b;
	int c;
	vector<int> d;
	for(int i=60;i>=0;i--)
	{
		e=pow(10,i);
		b=a/e;
		c=int (b);
		a=a-e*c;
		d.push_back(c);
	}
	int i=60;
	cout <<"Cac so hang d la: ";
	for(int j=0;j<d.size();j++)
	{
		cout <<d[j]<<" ung voi 10^"<<i-j;
		if(j!=d.size()-1)
		cout<<", ";
		if(j==d.size()-1)
		cout<<".";
	}
	return 0;
}
