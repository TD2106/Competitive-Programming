#include <iostream>
using namespace std;
string thu(int n)
{
	string s;
	int a=n%7;
	switch(a)
	{
		case 0:
			{
				return s="Chu nhat";
				break;
			}
		case 1:
			{
				return s="Thu hai";
				break;
			}
		case 2:
			{
				return  s="Thu ba";
				break;
			}
		case 3:
			{
				return s="Thu tu";
				break;
			}
		case 4:
			{
				return s="Thu nam";
				break;
			}
		case 5:
			{
				return s="Thu sau";
				break;
			}
		case 6:
			{
				return s="Thu bay";
				break;
			}
	}
}
int main ()
{
	int a,b,c,s=0;
	cout<<"Nhap a,b,c ";
	cin>>a>>b>>c;
	for(int i=1;i<b;i++)
	{
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
		s=s+31;
		if(i==2&&c%4!=0)
		s=s+28;
		if(i==2&&c%4==0)
		s=s+29;
		if(i==4||i==6||i==9||i==11)
		s=s+30;
	}
	s=s+a-1;
	cout<<thu(s);
	
}
