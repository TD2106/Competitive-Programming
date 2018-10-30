#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
bool cmp(int i)
{
	return (i>=n);
}
int main ()
{
	int tribo[1000]={0, 0, 1, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274, 504, 927, 1705, 3136, 5768, 10609, 19513,
	35890, 66012, 121415, 223317, 410744, 755476, 1389537, 2555757, 4700770, 8646064},i,temp=0;
	for(i=30;temp<=1000000000;i++)
	{
		temp=tribo[i-1]+tribo[i-2]+tribo[i-3];
		tribo[i]=temp;
	}
	vector<int> data(tribo,tribo+38);

	while(cin>>n)
	{	
		vector<int>::iterator itr=find_if(data.begin(),data.end(),cmp);
		cout<<*itr<<"\n";
	}
	return 0;
}
