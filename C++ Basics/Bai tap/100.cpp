#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ()
{
	fstream data;
	string s,s1;
	cout <<"Nhap chuoi can tim" << endl;
	getline (cin,s1);
	int k,a=0,b=0;
	data.open("f_100.txt",ios::in);
	while(!data.eof())
	{
		getline(data,s);
		b++;
		k=1;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]==s1[0]&&(i+s1.size())<=s.size())
			{
				k=0;
				for(int j=0;j<s1.size();j++)
				{
					if(s[i+j]!=s1[j])
					k=1;
				}
			}
			if(k==0)
			break;
			
		}
		if(k==0)
		{
			cout <<"Xau can tim xuat hien o dong " <<b<<endl;
			a++;
		}
		
	}
	if(a==0)
	cout<<"Ko co xau can tim trong file" << endl;
	return 0;
}
