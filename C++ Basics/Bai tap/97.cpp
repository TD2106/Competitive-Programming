#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ()
{
	fstream data;
	data.open("f_97.txt",ios::in);
	string s,s1,s2;
	int k,a,b;
	while(!data.eof())
	{
		getline(data,s);
		k=0;
		for(int i=0;i<s.size()-4;i++)
		{
			if(s[i]=='|'&&k==0)
			{
				a=i;
			}
			if(s[i]=='|')
			{
				k=k+1;
			}
			if(s[i]=='|'&&k==2)
			{
				b=i;
			}
			
		}
		for(int j=0;j<a;j++)
		s1=s1+s[j];
		for(int j=b+1;j<b+5;j++)
		s2=s2+s[j];
		if(s2[0]=='1'&&s2[1]=='9'&&s2[2]=='6'&&s2[3]=='0')
		{
			cout << s1 << endl;
		}
		
		s1.erase(0,s1.size());
		s2.erase(0,s2.size());
	}
	return 0;
}
