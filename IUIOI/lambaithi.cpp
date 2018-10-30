#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
void process(char arr[])
{
	int assign[3];
	int due[3];
	int timeinterval,require;
	char temp;
	cin >> assign[0] >> temp >> assign[1] >> temp >> assign[2] >> due[0] >> temp >> due[1] >> temp >> due[2] >> require;
	require=require*60;
	timeinterval=due[0]*3600+due[1]*60+due[2]-assign[0]*3600-assign[1]*60-assign[2];
	if(timeinterval<=0)
	timeinterval=timeinterval+86400;
	if(timeinterval>=require)
	cout<<"Perfect\n";
	else
	{
		if(timeinterval+3600>=require)
		cout<<"Extra\n";
		else
		cout<<"Fail\n";
	}
}
int main ()
{
	int n;
	char arr[100];
	cin>>n;
	cin.ignore();
	while(n--)
	{
		fgets(arr,100,stdin);
		while(!strlen(arr))
		fgets(arr,100,stdin);
		process(arr);
	}
	cout<<"\n";
	return 0;
}

