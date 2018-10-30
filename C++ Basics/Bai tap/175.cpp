#include <iostream>
using namespace std;
void xuli(string s)
{
	int i=s.size()-1;
	if(s[i]=='y')
	{
		s.erase(i,1);
		s=s+"ies";
	}
	else
	{
		if(s[i]=='s'||((s[i-1]=='s'||s[i-1]=='c')&&s[i]=='h'))
		s=s+"es";
		else
		s=s+"s";
	}
	cout<<s;
}
int main ()
{
	string s;
	cout<<"Nhap tu ";
	getline(cin,s);
	xuli(s);
	return 0;
}
