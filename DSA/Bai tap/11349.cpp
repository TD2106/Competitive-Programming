#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int process(string s)
{
	char number[5];
	memset(number,'\0',5);
	int j=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			number[j]=s[i];
			j++;
		}
	}
	int num;
	sscanf(number,"%d",&num);
	return num;
}

int main ()
{
	int cases,order=1;
	string s;
	//freopen("11349.txt","r",stdin);
	cin>>cases;
	cin.ignore();
	while(cases--)
	{
		int check=1;
		vector<double> data;
		getline(cin,s);
		int num=process(s);
		int dem=num*num;
		for(int i=0;i<dem;i++)
		{
			double temp;
			cin>>temp;
			if(temp>=0)
			{
				data.push_back(temp);
			}
			else
			{
				check=0;
			}
		}
		if(check==0)
		{
			cout<<"Test #"<<order<<": Non-symmetric."<<endl;
		}
		else
		{
			dem=dem-1;
			for(int i=0;i<data.size()/2;i++)
			{
				if(data[i]!=data[dem-i])
				{
					check=0;
					break;
				}
			}
			if(check==0)
			cout<<"Test #"<<order<<": Non-symmetric."<<endl;
			else
			cout<<"Test #"<<order<<": Symmetric."<<endl;
		}
		order++;
		cin.ignore();
		s.clear();
	}
	return 0;
}
