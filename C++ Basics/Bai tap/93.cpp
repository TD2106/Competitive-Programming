#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main ()
{
	fstream data;
	data.open("f_93.txt",ios::in);
	int a = 0;
	string s;
	while (data >> s)
	{
		a=a+1;
	}
	cout << a << endl;
	return 0;
}
