#include <iostream>
#include <algorithm>
using namespace std;
int array[11][11];
struct command 
{
	int com;
	int var1;
	int var2;
};
void inputarray(int n)
{
	string s;
	int test;
	char temp[2];
	temp[1]='\0';
	for(int i=1;i<=n;i++)
	{
		getline(cin,s);
		for(int j=1;j<=n;j++)
		{
			temp[0]=s[j-1];
			sscanf(temp,"%d",&test);
			array[i][j]=test;
		}	
		s.clear();
	}
}
command process(string s)
{
	command result;
	if(s[0]=='r')
	{
		result.com=1;
		int temp1,temp2;
		char a[2],b[2];
		a[0]=s[4];b[0]=s[6];
		a[1]='\0';b[1]='\0';
		sscanf(a,"%d",&temp1);
		sscanf(b,"%d",&temp2);
		result.var1=temp1;
		result.var2=temp2;
	}
	if(s[0]=='c')
	{
		result.com=2;
		int temp1,temp2;
		char a[2],b[2];
		a[0]=s[4];b[0]=s[6];
		a[1]='\0';b[1]='\0';
		sscanf(a,"%d",&temp1);
		sscanf(a,"%d",&temp1);
		sscanf(b,"%d",&temp2);
		result.var1=temp1;
		result.var2=temp2;
	}
	if(s[0]=='i')
	{
		result.com=3;
		result.var1=0;
		result.var2=0;
	}
	if(s[0]=='d')
	{
		result.com=4;
		result.var1=0;
		result.var2=0;
	}
	if(s[0]=='t')
	{
		result.com=5;
		result.var1=0;
		result.var2=0;
	}
	return result;
}
void row(command result,int n)
{
	for(int i=0;i<=n;i++)
	swap(array[result.var1][i],array[result.var2][i]);
}
void column(command result,int n)
{
	for(int i=0;i<=n;i++)
	swap(array[i][result.var1],array[i][result.var2]);
}
void increase(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			array[i][j]++;
			if(array[i][j]==10)
			array[i][j]=0;
		}
	}
}
void decrease(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			array[i][j]--;
			if(array[i][j]==-1)
			array[i][j]=9;
		}
	}
}
void transpose(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		swap(array[i][j],array[j][i]);
	}
}
void print(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		cout<<array[i][j];
		cout<<endl;
	}
}
int getnum(string s)
{
	char a[2];
	a[0]='\0';a[1]='\0';
	for(int i=0;i<s.size();i++)
	{
		a[i]=s[i];	
	}
	int result;
	sscanf(a,"%d",&result);
	return result;
}
int main ()
{
	string s;
	int testcase,n,dem=1;
	//freopen("11360.txt","r",stdin);
	cin>>testcase;
	cin.ignore();
	while(testcase--)
	{
		getline(cin,s);
		n=getnum(s);
		inputarray(n);
		int time;
		getline(cin,s);
		time=getnum(s);
		while(time--)
		{
			getline(cin,s);
			command result=process(s);
			if(result.com==1)
			row(result,n);
			if(result.com==2)
			column(result,n);
			if(result.com==3)
			increase(n);
			if(result.com==4)
			decrease(n);
			if(result.com==5)
			transpose(n);
		}
		cout<<"Case #"<<dem<<endl;
		print(n);
		cout<<endl;
		dem++;
	}
}
