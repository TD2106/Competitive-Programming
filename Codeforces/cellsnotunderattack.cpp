#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{
	//freopen("B.txt","r",stdin);
	long long n,m,temprow,tempcolumn,existcolumn=0,existrow=0,cal;
	cin>>n>>m;
	long long total=n*n;
	bitset<100001> row;
	bitset<100001> column;
	for(long long i=0;i<m;i++)
	{
		cal=0;
		cin>>temprow>>tempcolumn;
		if(!row[temprow])
		{
			row[temprow]=1;
			existrow++;
			cal+=n-existcolumn;
		}
		if(!column[tempcolumn])
		{
			column[tempcolumn]=1;
			existcolumn++;
			cal+=n-existrow;
		}
		total-=cal;
		cout<<total<<" ";
	}
	return 0;
}
