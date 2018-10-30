#include <iostream>
#include <fstream>
using namespace std;
int main ()
{
	fstream data;
	data.open("f_91.txt",ios::in);
	string s,s1;
	while (!data.eof())
	{
		getline(data,s1);
		s=s+s1+"\n";
	}
	s.erase(s.size()-1,1);
	int n = s.size();
	for (int i=0;i<n;i++)
	{
		if(s[i]==' '&&s[i+2]==' ')
		{
			s.erase(i+1,1);
		}
	}
	n = s.size();
	int j,a;
	for (int i=0;i<n;i++)
	{
		if(s[i]==' ')
		{
			j=i+1;
			a=0;
			while(s[j]==' ')
			{
				a++;
				j++;
			}
			s.erase(i,a);
		}
	}
	data.close();
	data.open("g_91.txt",ios::out);
	data << s;
	data.close();
	cout << " Shit was successfully executed" << endl;
	return 0;
}
