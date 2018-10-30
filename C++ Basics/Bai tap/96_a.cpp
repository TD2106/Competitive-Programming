#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	fstream data;
	data.open("f_96.txt",ios::in);
	string s1,s2,s5;
	char c1[3],c2[2],c3[4];
	int k=0;
	int a=12,b=9,c=2015;
	int p,q,r,max=0,s;
	while(!data.eof())
	{
		getline(data,s1);
		s=0;
		s2=s2+s1[3]+s1[4];
		if(s2[0]=='0')
		{
			if(s2[1]=='7'||s2[1]=='8'||s2[1]=='9')
			cout << s1 << " thuoc mua thu" << endl;
			k=1;
		}
		s2.erase(0,s2.size());
		c1[0]=s1[0];
		c1[1]=s1[1];
		c1[2]='\0';
		c2[0]=s1[3];
		c2[1]=s1[4];
		c2[2]='\0';
		c3[0]=s1[6];
		c3[1]=s1[7];
		c3[2]=s1[8];
		c3[3]=s1[9];
		c3[4]='\0';
		p=atoi(c1);
		q=atoi(c2);
		r=atoi(c3);
		s=(c-r)*365+(b-q)*30+(a-p);
		if(s>max)
		{
			max=s;
			s5=s1;
		}
	}
	if(k==0)
	cout<< " Ko co moc thoi gian nao thuoc mua thu" << endl;
	cout << "Moc thoi gian xa nhat la "<< s5 <<endl;
	data.close();
	
}
