#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main ()
{
	fstream data;
	data.open("f1.txt", ios::in) ;
	string s1,s2,s3;
	while (!data.eof())
	{
		getline(data,s1);
		s2=s2+s1+"\n";
	}
	
	data.close();
	data.open("f2.txt",ios::in);
	while (!data.eof())
	{
		getline(data,s1);
		s3=s3+s1+"\n";
	}
	data.close();
	ofstream data1;
	data1.open("f1.txt",ios::trunc);
	data1.close();
	data1.open("f2.txt",ios::trunc);
	data1.close();
	data.open("f1.txt",ios::out);
	data << s3;
	data.close();
	data.open("f2.txt");
	data << s2;
	data.close();
	cout << "Done";
}
