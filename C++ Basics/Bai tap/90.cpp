#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main ()
{
	fstream data;
	string s1,s2,s3;
	data.open("f_90.txt",ios::in);
	while (!data.eof())
	{
		getline(data,s3);
		s1=s1+s3+"\n";
	}
	s1.erase(s1.size()-1,1);
	data.close();
	data.open("g_90.txt",ios::in);
	while (!data.eof())
	{
		getline(data,s3);
		s2=s2+s3+"\n";
	}
	s2.erase(s2.size()-1,1);
	data.close();
	char a='f';
	int i = s2.size();
	if(s1.size()<s2.size())
	{
		i=s1.size();
		a='g';
	}
	int s=0;
	for(int j=0;j<i;j++)
	{
		if(s1[j]<s2[j])
		{
			cout << " File g lon hon " << endl;
			s=1;
			break;
		}
		if(s1[j]>s2[j])
		{
			cout << " File f lon hon " << endl;
			s=1;
			break;
		}
	}
	if(s==0)
	{
		cout << "File " << a << " lon hon" <<endl;
	}
	return 0;
}
