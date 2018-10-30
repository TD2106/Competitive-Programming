#include <iostream>
#include <vector>
using namespace std;
bool mark[4]={0};
vector< vector<long long> > permutation;
vector<long long> temp;
void thu(int i)
{
	for(long long j=0;j<4;j++)
	{
		if(!mark[j])
		{
			mark[j]=1;
			temp.push_back(j);
			if(i==3)
			permutation.push_back(temp);
			else
			thu(i+1);
			temp.pop_back();
			mark[j]=0;
		}
	}
}
int main ()
{
	thu(0);
	long long arr[4],min=10000000000;
	char magic[3];
	for(long long i=0;i<4;i++)
	cin>>arr[i];
	cin.ignore();
	for(long long i=0;i<3;i++)
	cin>>magic[i];
	for(long long i=0;i<24;i++)
	{
		long long rs;
		if(magic[0]=='+')
		rs=arr[permutation[i][0]]+arr[permutation[i][1]];
		else
		rs=arr[permutation[i][0]]*arr[permutation[i][1]];
		if(magic[1]=='+')
		rs+=arr[permutation[i][2]];
		else
		rs*=arr[permutation[i][2]];
		if(magic[2]=='+')
		rs+=arr[permutation[i][3]];
		else
		rs*=arr[permutation[i][3]];
		if(i==0)
		min=rs;
		else if(rs<min)
		min=rs;
	}
	cout<<min;
	return 0;
}
