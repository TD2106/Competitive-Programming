#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
struct info
{
	int id;
	int solvedproblem=0;
	int fail[7]={0};
	int totaltime=0;
};
void process(char str[],info &temp)
{
	int id,probnum;
	char problem;
	int hour,minute;
	char status;
	int time;
	sscanf(str,"%d %c %d %*c %d %c",&id,&problem,&hour,&minute,&status);
	temp.id=id;
	probnum=problem-65;
	if(status=='Y')
	{
		temp.solvedproblem++;
		temp.totaltime=temp.totaltime+temp.fail[probnum]*20+hour*60+minute;
	}
	else
	{
		temp.fail[probnum]++;
	}
}
int getid(char str[])
{
	int id;
	sscanf(str,"%d",&id);
	return id;
}
bool comp(const info &a, const info &b)
{
	return (a.solvedproblem>b.solvedproblem||((a.solvedproblem==b.solvedproblem)&&(a.totaltime<b.totaltime))||
	((a.solvedproblem==b.solvedproblem)&&(a.totaltime==b.totaltime)&&(a.id<b.id)));
}
int main ()
{
	freopen("790.txt","r",stdin);
	char str[100];
	int teamid,max=0,n;
	info team[30];
	max=0;
	while(fgets(str,100,stdin))
	{
		teamid=getid(str);
		if(teamid>max)
		max=teamid;
		process(str,team[teamid-1]);
	}
	for(int i=0;i<max;i++)
	team[i].id=i+1;
	vector<info> data(team,team+max);
	sort(data.begin(),data.end(),comp);
	int mark=1;
	cout<<"RANK TEAM PRO/SOLVED TIME\n";
	for(int i=0;i<data.size();i++)
	{
		if(i==0)
		{
			if(data[i].solvedproblem>0)
			cout<<"   "<<i+1<<"    "<<data[i].id<<"    "<<data[i].solvedproblem<<"        "<<data[i].totaltime;
		    else
			cout<<"   "<<i+1<<"    "<<data[i].id<<"    "<<" "<<"        "<<"   ";
		}
		else
		{
			if(data[i].solvedproblem==data[i-1].solvedproblem&&data[i].totaltime==data[i-1].totaltime)
			{
				if(data[i].solvedproblem>0)
				cout<<"   "<<mark<<"    "<<data[i].id<<"    "<<data[i].solvedproblem<<"        "<<data[i].totaltime;
				else
				cout<<"   "<<mark<<"    "<<data[i].id<<"    "<<" "<<"        "<<"   ";
			}
			else
			{
				if(data[i].solvedproblem>0)
				cout<<"   "<<++mark<<"    "<<data[i].id<<"    "<<data[i].solvedproblem<<"        "<<data[i].totaltime;
				else
				cout<<"   "<<++mark<<"    "<<data[i].id<<"    "<<" "<<"        "<<"   ";
			}
		}
		cout<<"\n";
	}
	return 0;
}

