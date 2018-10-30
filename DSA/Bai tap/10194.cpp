#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <map>
#include <string>
using namespace std;

struct information
{
	string name;
	int point=0;
	int win=0,lose=0,tie=0;
	int difference=0;
	int goal=0;
	int game=0;
};

bool comparestruct(const information &a,const information &b)
{
	return (a.point>b.point||((a.point==b.point)&&(a.win>b.win))||((a.point==b.point)&&(a.win==b.win)&&(a.difference>b.difference))||
	((a.point==b.point)&&(a.win==b.win)&&(a.difference==b.difference)&&(a.goal>b.goal))||
	((a.point==b.point)&&(a.win==b.win)&&(a.difference==b.difference)&&(a.goal==b.goal)&&(a.game>b.game))||
	((a.point==b.point)&&(a.win==b.win)&&(a.difference==b.difference)&&(a.goal==b.goal)&&(a.game==b.game)&&(a.name<b.name)));
}
void addinfotostruct(string s,information &a,information &b)
{
	a.game++;
	b.game++;
	char array[100] ;
	strcpy(array, s.c_str());
	int goal1,goal2;
	sscanf(array,"%d %d",&goal1,&goal2);
	if(goal1>goal2)
	{
		a.point+=3;
		a.goal+=goal1;
		a.win++;
		a.difference+=goal1-goal2;
		b.goal+=goal2;
		b.difference+=goal2-goal1;
		b.lose++;
	}
	else
	{
		if(goal1<goal2)
		{
			b.point+=3;
			a.goal+=goal1;
			b.win++;
			a.difference+=goal1-goal2;
			b.goal+=goal2;
			b.difference+=goal2-goal1;
			a.lose++;
		}
		else
		{
			b.point++;
			a.point++;
			a.goal+=goal1;
			b.goal+=goal2;
			a.tie++;
			b.tie++;
		}
	}
}
void processstr(string &s,string &name1, string &name2)
{
	string temp;
	int mark1,mark2,check=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='#'||s[i]=='@')
		{
			if(s[i]=='#'&&check%2==1)
			{
				mark1=i;
				check++;
			}
			else if(s[i]=='#'&&check%2==0)
			{
				mark2=i;
				check++;
			}
			s[i]=' ';
		}
	}
	for(int i=mark1+1;i<mark2;i++)
	temp=temp+s[i];
	name1=s.substr(0,mark1);
	name2=s.substr(mark2+1,s.size()-mark2-1);
	s=temp;
}
void printstruct(information &a,int i)
{
	cout<<i<<") "<<a.name<<" "<<a.point<<"p, "<<a.game<<"g ("<<a.win<<"-"<<a.tie<<"-"<<a.lose<<"), "<<a.difference<<"gd ("<<a.goal<<"-"<<a.goal-a.difference<<")\n";
}
int main ()
{
	//freopen("10194.txt","r",stdin);
	map<string,int> index;
	vector<string> name;
	vector<information> team;
	information temporary;
	string tournament,s;
	int N,K;
	char num[10];
	fgets(num,10,stdin);
	sscanf(num,"%d",&N);
	while(N--)
	{
		getline(cin,tournament);
		fgets(num,10,stdin);
		sscanf(num,"%d",&K);
		while(K--)
		{
			getline(cin,s);
			name.push_back(s);
		}
		sort(name.begin(),name.end());
		for(int i=0;i<name.size();i++)
		{
			index[name[i]]=i;
			temporary.name=name[i];
			team.push_back(temporary);
		}
		fgets(num,10,stdin);
		sscanf(num,"%d",&K);
		while(K--)
		{
			getline(cin,s);
			string name1,name2;
			processstr(s,name1,name2);
			addinfotostruct(s,team[index[name1]],team[index[name2]]);
		}
		sort(team.begin(),team.end(),comparestruct);
		cout<<tournament<<"\n";
		for(int i=0;i<team.size();i++)
		{
			printstruct(team[i],i+1);
		}
		cout<<endl;
		index.clear();
		name.clear();
		team.clear();
	}
	return 0;
}
