#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main ()
{
	fstream data;
	string s1,s2,s3;
	data.open("86_1.txt",ios::in);
	while (!data.eof())
	{
		getline(data,s1);
		s2=s2+s1+"\n";
	}
	data.close();
	int i=0;
	while(s2[i]!='\0')
	{
		if(s2[i]>='A'&&s2[i]<='Z')
		s2[i]=s2[i]+32;
		i++;
	}
	data.open("86_2.txt",ios::out);
	data << s2;
	data.close();
	cout << "Done";
	return 0;
}
