#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ()
{
	fstream data;
	string s;
	int i=1,a=0;
	data.open("f_98.txt",ios::in);
	while (!data.eof())
	{
		getline(data,s);
		if(s.size()>50)
		{
			cout << "Dong "<<i<<" co hon 50 ki tu" << endl;
			a=1;
		}
		i++;
	}
	if(a==0)
	cout << "Ko co dong nao thoa dieu kien de bai" << endl;
	data.close();
	return 0;
}
