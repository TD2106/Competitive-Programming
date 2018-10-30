#include <iostream>
#include <string>
using namespace std;
string trim(string &s)
{
	string result;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9'||s[i]=='X'||s[i]=='/')
		result+=s[i];
	}
	return result;
}
int main ()
{
	int test,indexpoint,indexstatus,sum,temp;
	cin>>test;
	cin.ignore();
	string s,input;
	while(test--)
	{
		sum=0;
		indexpoint=0;
		indexstatus=0;
		int point[30]={0},status[15]={0};
		getline(cin,s);
		input=trim(s);
		for(int i=0;i<input.size();i++)
		{
			if(indexstatus==9)
			{
				if(input[i]=='X')
				{
					sum+=10;
					point[indexpoint]=10;
					indexpoint++;
					if(input[i+1]=='X')
					{
						sum+=10;
						point[indexpoint]=10;
						indexpoint++;
						if(input[i+2]=='X')
						sum+=10;
						else
						sum+=input[i+2]-'0';
					}
					else
					{
						point[indexpoint]=input[i+1]-'0';
						indexpoint++;
						if(input[i+2]=='/')
						sum+=10;
						else
						sum+=input[i+1]-'0'+input[i+2]-'0';
					}
				}
				else
				{
					point[indexpoint]=input[i]-'0';
					indexpoint++;
					if(input[i+1]>='0'&&input[i+1]<='9')
					{
						sum+=input[i]-'0'+input[i+1]-'0';
						point[indexpoint]=input[i+1]-'0';
						indexpoint++;
					}
					else
					{
						sum+=10;
						point[indexpoint]=10-point[indexpoint-1];
						indexpoint++;
						if(input[i+2]=='X')
						sum+=10;
						else
						sum+=input[i+2]-'0';
					}
				}
				break;
			}
			if(input[i]=='X')
			{
				status[indexstatus]=1;
				point[indexpoint]=10;
				indexstatus++;
				indexpoint++;
			}
			else if(input[i]>='0'&&input[i]<='9')
			{
				point[indexpoint]=input[i]-'0';
				indexpoint++;
				i++;
				if(input[i]=='/')
				{
					status[indexstatus]=2;
					point[indexpoint]=10-point[indexpoint-1];
				}
				else
				{
					point[indexpoint]=input[i]-'0';
					status[indexstatus]=3;
				}
				indexpoint++;
				indexstatus++;
			}
		}
		int j=0;
		for(int i=0;i<9;i++)
		{
			if(status[i]==1)
			{
				sum+=point[j]+point[j+1]+point[j+2];
				j++;
			}
			else if(status[i]==2)
			{
				sum+=point[j]+point[j+1]+point[j+2];
				j+=2;
			}
			else
			{
				sum+=point[j]+point[j+1];
				j+=2;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
