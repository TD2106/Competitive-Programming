#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

string daonguoc (string s)
{
	int i=s.size()/2;
	char d;
	for(int j=0;j<i;j++)
	{
		d=s[j];
		s[j]=s[s.size()-1-j];
		s[s.size()-1-j]=d;
	}
	return s;
}

int main ()
{
	fstream data;
	vector <string> a;
	string s,s1;
	int i=0;
	data.open("f_99.txt",ios::in);
	while(!data.eof())
	{
		getline(data,s1);
		a.push_back(daonguoc(s1));
		s1.erase(0,s1.size());
		i++;
	}
	data.close();
	for(int j=0;j<i;j++)
	{
		s=s+a[j]+"\n";
		s1=s1+a[i-j-1]+"\n";
	}
	data.open("g1_99.txt",ios::out);
	data << s;
	data.close();
	data.open("g2_99.txt",ios::out);
	data << s1;
	data.close();
	return 0;
}
