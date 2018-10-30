#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ()

{
	fstream data;
	data.open("f_95.txt",ios::in);
	string s1;
	cout << " Nhap bien so xe 8 ki tu can tim " << endl;
	string s2;
	getline(cin,s2);
	if(s2.size()!=8)
	{
		cout <<"Nhap bien so xe ko hop le" <<endl;
		exit(0);
	}
	int a=1,b;
	while (!data.eof())
	{
		getline(data,s1);
		
		a=1;
		for (int i=0;i<s1.size();i++)
		{
			if(s1[i]=='|')
			{
				b=i;
			}
			if(s1[i]==s2[0])
			{
				a=0;
				for(int j=0;j<s2.size();j++)
				{
					if(s1[i+j]!=s2[j])
					a=1;
				}
			}
			if(a==0)
			{
				for(int j=0;j<b;j++)
				cout << s1[j];
				cout<<endl;
			}
			if(a==0)
			break;
			
		}
		if(a==0)
		break;
	}
	if(a==1)
	cout<<"Ko co xe nao co bien so nhu vay"<<endl;
	data.close();
	data.open("f_95.txt",ios::in);
	cout << "Nhap so seri bien so gom 3 ki tu" <<endl;
	getline(cin,s2);
	if(s2.size()!=3)
	{
		cout << "So seri sai";
		exit(0);
	}
	a=1;
	int k=0;
	while(!data.eof())
	{
		getline(data,s1);
		a=1;
		for(int i=0;i<s1.size();i++)
		{
			if(s1[i]==s2[0])
			{
				a=0;
				for(int j=0;j<s2.size();j++)
				{
					if(s1[i+j]!=s2[j])
					a=1;
				}
			}
		}
		if(a==0)
		k=k+1;
	}
	if(k>0)
	cout << "So xe co bien so co so seri da nhap la " << k <<endl;
	if(k==0)
	cout <<"Ko co xe nao co so seri nhu da nhap"<<endl;
	data.close();
	return 0;
	
}
