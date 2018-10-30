#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
void process()
{
	int input[7];
	scanf("%d:%d:%d %d:%d:%d %d",&input[0],&input[1],&input[2],&input[3],&input[4],&input[5],&input[6]);
	int period=input[3]*3600+input[4]*60+input[5]-input[0]*3600-input[1]*60-input[2];
	if(period<=0)
	period+=86400;
	input[6]*=60;
	if(period>=input[6])
	cout<<"Perfect\n";
	else if(period+3600>=input[6])
	cout<<"Extra\n";
	else
	cout<<"Fail\n";
}
int main ()
{
	int testcase;
	scanf("%d",&testcase);
	while(testcase--)
	{
		process();
	}
	return 0;
}
