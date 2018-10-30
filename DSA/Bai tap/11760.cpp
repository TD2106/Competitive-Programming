#include <iostream>
#include <bitset>
using namespace std;
int main ()
{
	bitset<10002> row;
	bitset<10002> column;
	int R,C,N,aR,aC,r,c,count=1;
	//freopen("11760.txt","r",stdin);
	cin>>R>>C>>N;
	while(R)
	{
		row[0]=1;
		column[0]=1;
		row[10001]=1;
		column[10001]=1;
		while(N--)
		{
			cin>>r>>c;
			row[r+1]=1;
			column[c+1]=1;
		}
		cin>>aR>>aC;
		if(aR+2>R)
		row[aR+2]=1;
		if(aC+2>C)
		column[aC+2]=1;
		if(!((row[aR+1]|column[aC+1])&(row[aR+1]|column[aC])&(row[aR+1]|column[aC+2])&(row[aR]|column[aC+1])&(row[aR+2]|column[aC+1])))
		cout<<"Case "<<count<<": Escaped again! More 2D grid problems!\n";
		else
		cout<<"Case "<<count<<": Party time! Let's find a restaurant!\n";
		count++;
		cin>>R>>C>>N;
		row.reset();
		column.reset();
	}
	return 0;
}
