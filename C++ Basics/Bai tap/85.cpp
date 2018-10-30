#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main ()
{
	string s1,s2,s3,s4,s5,s6;
	fstream data;
	data.open("f1.txt",ios::in);
	while (!data.eof())
	{
		getline(data,s6);
		s1=s1+s6+"\n";
	}
	data.close();
	data.open("f2.txt",ios::in);
	while (!data.eof())
	{
		getline(data,s6);
		s2=s2+s6+"\n";
	}
	data.close();
	data.open("f3.txt",ios::in);
	while (!data.eof())
	{
		getline(data,s6);
		s3=s3+s6+"\n";
	}
	data.close();
	data.open("f4.txt",ios::in);
	while (!data.eof())
	{
		getline(data,s6);
		s4=s4+s6+"\n";
	}
	data.close();
	data.open("f5.txt",ios::in);
	while (!data.eof())
	{
		getline(data,s6);
		s5=s5+s6+"\n";
	}
	data.close();
	ofstream data1;
	data1.open("f1.txt",ios::trunc);
	data1.close();
	data1.open("f2.txt",ios::trunc);
	data1.close();
	data1.open("f3.txt",ios::trunc);
	data1.close();
	data1.open("f4.txt",ios::trunc);
	data1.close();
	data1.open("f5.txt",ios::trunc);
	data1.close();
	data.open("f1.txt",ios::out);
	data << s5;
	data.close();
	data.open("f2.txt",ios::out);
	data << s4;
	data.close();
	data.open("f3.txt",ios::out);
	data << s1;
	data.close();
	data.open("f4.txt",ios::out);
	data << s2;
	data.close();
	data.open("f5.txt",ios::out);
	data << s3;
	data.close();
	cout << "Shit was successfully executed";
	return 0;
	
}
