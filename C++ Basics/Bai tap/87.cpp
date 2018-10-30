#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main ()
{
	fstream data;
	string s1,s2,s3;
	data.open("87.txt",ios::in);
	while (!data.eof())
	{
		getline(data,s1);
		s2=s2+s1+"\n"; 
	}
	data.close();
	s2.erase(s2.size()-1,1);
	int i = s2.size()-1;
	for (int j=0;j<=i;j++)
	{
		s3+=s2[i-j];
	}
	data.open("87_2.txt",ios::out);
	data << s3;
	data.close();
	cout << "Done";
	return 0;
}
