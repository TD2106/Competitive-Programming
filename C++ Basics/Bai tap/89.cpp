#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ()
{
	string s1;
	int k=0;
	fstream data;
	data.open ("89.txt",ios::in);
	while (data >> s1)
	{
		int i = s1.size();
		for (int j=0;j<i-1;j++)
		{
			if(s1[j]=='a'&&s1[j+1]=='b')
			k=k+1;
		}
	}
	cout <<"So lan chuoi ab xuat hien la " << k << endl;
	data.close();
	// cau b
	int array[26],i,j=0;
	for (i=0;i<26;i++)
	{
		array[i]=0;
		char test = 'a'+i;
		data.open("89.txt",ios::in);
		while (data >> s1)
		{
			for (j=0;j<s1.size();j++)
			{
				if(s1[j]==test)
				array[i]=array[i]+1;
			}
		}
		cout << "So lan xuat hien cua ky tu " << test << " la : " << array[i] << endl;
		data.close();
	}
	
	return 0;
}
