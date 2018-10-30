////Chi doc dc toi 9 chu so, len nua thì them vao function don vi;
#include <iostream>
#include <string>
using namespace std;
string so(char a)
{
	string s;
	switch (a)
	{
		case '1':
			{
				s="mot ";
				break;
			}
		case '2':
			{
				s="hai ";
				break;
			}
		case '3':
			{
				s="ba ";
				break;
			}
		case '4':
			{
				s="bon ";
				break;
			}
		case '5':
			{ 
				s="nam ";
				break;
			}
		case '6':
			{
				s="sau ";
				break;
			}
		case '7':
			{
				s="bay ";
				break;
			}
		case '8':
			{
				s="tam ";
				break;
			}
		case '9':
			{
				s="chin ";
				break;
			}
		case '0':
			{
				s="khong ";
				break;
			}
	}
	return s;
}
string giatri(string s)
{
	string s2;
	if(s.size()==3) s2="tram ";
	if(s.size()==2) s2="muoi ";
	if(s.size()==1) s2=" ";
	return s2;
}
string donvi(int n)
{
	string s;
	if(n>6) s="trieu ";
	if(n>3&&n<=6) s="ngan ";
	if(n<=3) s='\0';
	return s;
}
int check(string s)
{
	int a=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]<'0'||s[i]>'9')
		a=1;
	}
	return a;
}
int main ()
{
	string s,s1,s2,s3,s4;
	getline(cin,s);
	if(check(s))
	{
		cout<<"Nhap sai";
		exit(0);
	}
	while(s.size()!=0)
	{
		int a;
		if(s.size()>6) a=s.size()-6;
		if(s.size()<=6&&s.size()>3) a=s.size()-3;
		if(s.size()<=3) a=s.size();
		for(int i=0;i<a;i++)
		s2=s2+s[i];
		while(s2.size()!=0)
		{
			if(s2.size()==3&&s2[1]=='0'&&s2[2]=='0')
			{
				s4=so(s2[0])+giatri(s2);
				s1=s1+s4;
				s2.erase(0,a);
				break;
				
			}
			s4=so(s2[0])+giatri(s2);
			if(s4=="khong muoi ")
			s4="linh ";
			if(s4=="mot muoi ")
			s4="muoi ";
			s1=s1+s4;
			s2.erase(0,1);
		}
		s3=s3+s1+donvi(s.size());
		s1.erase(0,s1.size());
		s.erase(0,a);
	}
	cout<<s3;	
}
