#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
using namespace std;

string xuli(string s)
{
	string result;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		result=result+s[i];
		if(s[i]>='A'&&s[i]<='C')
		result=result+"2";
		if(s[i]>='D'&&s[i]<='F')
		result=result+"3";
		if(s[i]>='G'&&s[i]<='I')
		result=result+"4";
		if(s[i]>='J'&&s[i]<='L')
		result=result+"5";
		if(s[i]>='M'&&s[i]<='O')
		result=result+"6";
		if(s[i]>='P'&&s[i]<='S'&&s[i]!='Q')
		result=result+"7";
		if(s[i]>='T'&&s[i]<='V')
		result=result+"8";
		if(s[i]>='W'&&s[i]<='Y')
		result=result+"9";
	}
	result.insert(3,"-");
	return result;
}
int main ()
{
	map<string,int> data;
	map<string,int>::iterator itr;
	int n,check;
	string s;
	long int dem;
	//freopen("755.txt","r",stdin);
	cin>>n;
	while(n--)
	{
		map<string,int> dup;
		check=1;
		cin>>dem;
		fflush(stdin);
		while(dem--)
		{
			getline(cin,s);
			if(s=="\n")
			{
				dem++;
				continue;
			}
			if(s.size()<3)
			{
				dem++;
				continue;
			}
			s=xuli(s);
			data[s]++;
			if(data[s]>=2)
			{
				check=0;
				dup[s]=data[s];
			}
		}
		if(check)
		cout<<"No duplicates."<<endl;
		else
		{
			for(itr=dup.begin();itr!=dup.end();++itr)
			cout<<itr->first<<" "<<itr->second<<endl;
		}
		cout<<endl;
		data.clear();
	}
	return 0;
}
