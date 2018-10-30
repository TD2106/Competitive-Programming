#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main ()
{
	fstream data;
	data.open("f_92.txt",ios::in);
	int max = 0;
	string s,s1;
	while (data >> s)
	{
		if(s.size()>max)
		{
			s1=s;
			max=s.size();
		}
	}
	cout << s1 << endl;
	return 0;
}
