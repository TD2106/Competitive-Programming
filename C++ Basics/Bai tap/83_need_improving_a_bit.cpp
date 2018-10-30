#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main ()
{
	fstream data;
	data.open("83_1.txt", ios::in) ;
	string s1,s2;
	while (!data.eof())
	{
		getline(data,s1);
		s2=s2+s1+"\n";
	}
	
	data.close();
	data.open("83_2.txt",ios::out);
	data << s2;
	return 0;
	 
	
}
