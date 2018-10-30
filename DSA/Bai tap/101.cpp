#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
int block[30][30];
using namespace std;
struct number
{
	int a;
	int b;
};
//ham xac dinh menh lenh
/*int process(string s)
{
	int count=0,i;
	string s1=s.substr(0,4);
	for(i=0;i<s.size();i++)
	{
		if(s[i]==' ')
		count++;
		if(count==2)
		break;
	}
	string s2=s.substr(i+1,4);
	string test1="move",test2="pile",test3="onto",test4="over";
	if(s1==test1&&s2==test3)
	return 1;
	if(s1==test1&&s2==test4)
	return 2;
	if(s1==test2&&s2==test3)
	return 3;
	if(s1==test2&&s2==test4)
	return 4;
}*/

int process(string s)
{
	char tmp[s.size()+1];
	strcpy(tmp,s.c_str());
	char check1[10],check2[10];
	sscanf(tmp,"%s %*d %s %*d",check1,check2);
	if(check1[0]=='m'&&check2[1]=='n')
	return 1;
	if(check1[0]=='m'&&check2[1]=='v')
	return 2;
	if(check1[0]=='p'&&check2[1]=='n')
	return 3;
	if(check1[0]=='p'&&check2[1]=='v')
	return 4;
}

//ham tach so khoi string
number getnum(string s)
{
	char tmp[s.size()+1];
	strcpy(tmp,s.c_str());
	int temp1,temp2;
	sscanf(tmp,"%*s %d %*s %d",&temp1,&temp2);
	number data;
	data.a=temp1;
	data.b=temp2;
	return data;
}
//ham tim vi tri so can xu li
number position(int a,int n)
{
	int i,j,check=0;
	for(i=0;i<n;i++)
	{
		check=0;
		if(block[0][i]>=0)
		{
			for(j=0;j<n;j++)
			{
				if(block[j][i]==a)
				{
					check=1;
					break;
				}
				if(block[j][i]<0)
				break;
			}
			if(check)
			break;
		}
	}
	number find;
	find.a=i;//cot
	find.b=j;//hang
	return find;
}
int main ()
{
	int n;
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		block[i][j]=-1;
	}
	for(int i=0;i<n;i++)
	block[0][i]=i;
	string s;
	getline(cin,s);
	while(s!="quit")
	{
		int test=process(s);
		number num=getnum(s);
		number find1=position(num.a,n);
		number find2=position(num.b,n);
		if(test==1)
		{
			if(find1.a!=find2.a){
			for(int i=find1.b+1;i<n;i++)
			{
				if(block[i][find1.a]>=0)
				{
					block[0][block[i][find1.a]]=block[i][find1.a];
					block[i][find1.a]=-1;
				}
				else
				break;
			}
			for(int i=find2.b+1;i<n;i++)
			{
				if(block[i][find2.a]>=0)
				{
					block[0][block[i][find2.a]]=block[i][find2.a];
					block[i][find2.a]=-1;
				}
				else
				break;
			}
			swap(block[find1.b][find1.a],block[find2.b+1][find2.a]);
		    }
		}
		if(test==2)
		{
			if(find1.a!=find2.a){
			for(int i=find1.b+1;i<n;i++)
			{
				if(block[i][find1.a]>=0)
				{
					block[0][block[i][find1.a]]=block[i][find1.a];
					block[i][find1.a]=-1;
				}
				else
				break;
			}
			for(int i=find2.b+1;i<n;i++)
			{
				if(block[i][find2.a]<0)
				{
					swap(block[find1.b][find1.a],block[i][find2.a]);
					break;
				}
			}
			}
		}
		if(test==3)
		{
			if(find1.a!=find2.a){
			for(int i=find2.b+1;i<n;i++)
			{
				if(block[i][find2.a]>=0)
				{
					block[0][block[i][find2.a]]=block[i][find2.a];
					block[i][find2.a]=-1;
				}
				else
				break;
			}
			int tmp=find2.b+1;
			for(int i=find1.b;i<n;i++)
			{
				if(block[i][find1.a]>=0)
				{
					swap(block[i][find1.a],block[tmp][find2.a]);
					tmp++;
				}
				else
				break;
			}
		    }
		}
		if(test==4)
		{
			if(find1.a!=find2.a){
			int tmp=find1.b;
			for(int i=find2.b;i<n;i++)
			{
				if(block[i][find2.a]<0)
				{
					swap(block[i][find2.a],block[tmp][find1.a]);
					tmp++;
				}
			}
			}
		}
		getline(cin,s);
	}
	for(int i=0;i<n;i++)
	{
		cout<<i<<":";
		if(block[0][i]>=0)
		{
			for(int j=0;j<n;j++)
			if(block[j][i]>=0)
			cout<<" "<<block[j][i];
			else
			break;
		}
		cout<<endl;
	}
	return 0;
}
