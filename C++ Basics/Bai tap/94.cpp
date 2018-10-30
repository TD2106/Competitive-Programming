#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string hodemten (string s)
{
	int a,b,c,k=1;
	string s1,s2;
	for (int i=0;i<s.size();i++)
	{
		if(s[i]==' '&&k==2)
		{
			b=i;
			k++;
			for(int j=a+1;j<b;j++)
			{
				s1=s1+s[j];
			}
		}
		
		if(s[i]==' '&&k==1)
		{
			k++;
			a=i;
		}
	}
	for(int i=b+1;i<s.size();i++)
	{
		s2=s2+s[i];
	}
	s.erase(a,s1.size()+1);
	s=s+" "+s1;
	return s;
}


int main ()
{
	string s1,s2,s3;
	fstream data;
	data.open("f_94.txt",ios::in);
	while (!data.eof())
	{
		getline(data,s3);
		s1=s1+s3+"\n";
		
	}
	data.close();
	s3.erase(0,s3.size());
	s1.erase(s1.size()-1,1);
	for (int i=0;i<s1.size();i++)
	{
		if(s1[i]==',')
		{
			s1.erase(i-s3.size(),s3.size());
			s1.insert(i-s3.size(),hodemten(s3));
			s3.erase(0,s3.size());
			i=i+2;		
		}
		
		s3=s3+s1[i];
	}
	data.open("g_94.txt",ios::out);
	data << s1;
	cout << "Shit was done" << endl;
	data.close();
	return 0;
	
	
}
