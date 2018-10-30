#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main ()
{
	int b;
	vector <int> a;
	fstream data;
	data.open("88.txt",ios::in);
	while (!data.eof())
	{
		data >> b;
		a.push_back(b);
	}
	data.close();
    b = a.size()-1;
	for( int i =0; i<=b ; i++)
	{
		a[i]=a[i]+1;
	}
	data.open("88_2.txt",ios::out);
	for (int i = 0; i<=b; i++)
	{
		data << a[i];
		data << " ";
	}
	data.close();
	cout << "Done";
	return 0;
}

