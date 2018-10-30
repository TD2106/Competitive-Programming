#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

string daonguoc(string s)
{
	int n=s.size()/2,a=s.size()-1;
	char d;
	for(int i=0;i<n;i++)
	{
		d=s[i];
		s[i]=s[a];
		s[a]=d;
		a--;
	}
	return s;
}

int main ()
{
	fstream data;
	data.open("f_99.txt",ios::in);
	string s,s1,s2;
	int i=0;
	while (!data.eof())
	i++;
	data.close();
	string s3[i];
	i=i-1;
	int a=i;
	data.open("f__99.txt",ios::in);
	while(!data.eof())
	{
		getline(cin,s1);
		s=s+daonguoc(s1)+"\n";
		s3[i]=daonguoc(s1);
		i--;
	}
	s.erase(s.size()-1,1);
	for(int j=a;j>=0;j--)
	{
		s2=s2+s3[j]+"\n";
	}
	s2.erase(s2.size()-1,1);
	data.close();
	cout << s <<endl;
	cout << s2 << endl;
	return 0;
	
}
