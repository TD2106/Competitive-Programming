#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
struct information
{
	int solved=0;
	int fail[10]={0};
	int problemstt[10]={0};
	int time=0;
	int id;
};
void processstr(int teamparticipate[],char string[],information &contestant)
{
	int id,problem,time;
	char status;
	sscanf(string,"%d %d %d %c",&id,&problem,&time,&status);
	contestant.id=id;
	if(status=='R'||status=='U'||status=='E')
	{
		teamparticipate[id]=1;
		return;
	}
	if(status=='I')
	{
		contestant.fail[problem]++;
		teamparticipate[id]=1;
		return;
	}
	if(status=='C'&&contestant.problemstt[problem]==0)
	{
		contestant.problemstt[problem]=1;
		contestant.solved++;
		contestant.time=contestant.time+time+contestant.fail[problem]*20;
		teamparticipate[id]=1;
		return;
	}
}
bool compare(const information &a, const information &b)
{
	return (a.solved>b.solved||((a.solved==b.solved)&&(a.time<b.time))||((a.solved==b.solved)&&(a.time==b.time)&&(a.id<b.id)));
}
int getid(char string[])
{
	int id;
	sscanf(string,"%d %*d %*d %*c",&id);
	return id;
}
int main ()
{
	char string [50],num[10];
	vector<information> data;
	int testcase;
	//freopen("10258.txt","r",stdin);
	gets(num);
	sscanf(num,"%d",&testcase);
	getchar();
	while(testcase--)
	{
		information team[105];
		int teamparticipate[105]={0},max=0;
		while(gets(string)&&strlen(string))
		{
			int teamid=getid(string);
			if(teamid>max) max=teamid;
			processstr(teamparticipate,string,team[teamid]);
		}
		for(int i=1;i<=max;i++)
		{
			if(teamparticipate[i])
			data.push_back(team[i]);
		}
		sort(data.begin(),data.end(),compare);
		for(int i=0;i<data.size();i++)
		cout<<data[i].id<<" "<<data[i].solved<<" "<<data[i].time<<"\n";
		if(testcase)
		cout<<"\n";
		data.clear();
	}
	return 0;
}
