#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main ()
{
	fstream data;
	int b,c,f=0;
	vector<string> a;
	vector<string> d;
	vector<int> e;
	string s,s1,s2;
	data.open("f_101.txt",ios::in);
	while (!data.eof())
	{
		getline (data,s);
		for (int i=0;i<s.size();i++)
		{
			if(s[i]=='|')
			{
				c=i;
				break;
			}
			if(s[i]!='|')
			s1=s1+s[i];
		}
		for(int i=c+1;i<s.size();i++)
		{
			s2=s2+s[i];
		}
		if(s2[0]=='1'&&s2[1]=='0')
		f++;
		b=0;
		for(int j=0;j<d.size();j++)
		{
			if(s2==d[j])
			{
				b=1;
				e[j]=e[j]+1;
			}
			
		}
		if(b==0)
		{
			d.push_back(s2);
			e.push_back(1);
		}
		b=0;
		for( int j=0;j<a.size();j++)
		{
			if(a[j]==s1)
			cout << "Ho va ten cua 2 hoc sinh trung ten nhau la: " << s1 << endl;
			b=1;
		}
		if(b==0)
		a.push_back(s1);
		s1.erase(0,s1.size());
		s2.erase(0,s2.size());
		
	}
	data.close();
	for( int j=0;j<d.size();j++)
	{
		cout << "Lop " << d[j] << " co " << e[j] << " hoc sinh" << endl; 
	}
	cout <<"So hoc sinh lop 10 la " << f << endl;
}
