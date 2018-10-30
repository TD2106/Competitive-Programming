#include <iostream>
using namespace std;
int main ()
{
	int tc,s1=0,s2=0;
	cin>>tc;
	cin.ignore();
	while(tc--)
	{
		s1=0,s2=0;
		string s;
		cin>>s;
		int temp=s.size();
		for(int i=0;i<temp-3;i++)
		{
			if(s[i]=='S'&&s[i+1]=='U'&&s[i+2]=='V'&&s[i+3]=='O')
			s1++;
		}
		for(int i=0;i<temp-6;i++)
		{
			if(s[i]=='S'&&s[i+1]=='U'&&s[i+2]=='V'&&s[i+3]=='O'&&s[i+4]=='J'&&s[i+5]=='I'&&s[i+6]=='T')
			s2++;
		}
		cout<<"SUVO = "<<s1-s2<<", SUVOJIT = "<<s2<<endl;
	}
	return 0;
}
