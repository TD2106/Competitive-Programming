#include <iostream>
#include <bitset>
#include <algorithm>
#include <vector>
using namespace std;
int main ()
{
	bitset<100001> row,col;
	long long numrow,numcol,tc,n,m,q,temp1,temp2;
	vector<long long> metrow,metcol;
	cin>>tc;
	while(tc--)
	{
		cin>>n>>m>>q;
		row[1]=1;
		row[n]=1;
		col[1]=1;
		col[m]=1;
		metrow.push_back(1);
		metrow.push_back(n);
		metcol.push_back(1);
		metcol.push_back(m);
		for(int i=0;i<q;i++)
		{
			cin>>temp1>>temp2;
			if(!row[temp1])
			{
				row[temp1]=1;
				metrow.push_back(temp1);
			}
			if(!col[temp2])
			{
				col[temp2]=1;
				metcol.push_back(temp2);
			}
		}
		long long mxrow=-1,mxcol=-1,minrow=100001,mincol=100001;
		sort(metrow.begin(),metrow.end());
		sort(metcol.begin(),metcol.end());
		/*for(int i=0;i<metrow.size();i++)
		cout<<metrow[i]<<" ";
		cout<<endl;
		for(int i=0;i<metcol.size();i++)
		cout<<metcol[i]<<" ";
		cout<<endl;*/
		for(int i=0;i<metrow.size()-1;i++)
		{
			if(metrow[i+1]-metrow[i]>mxrow)
			mxrow=metrow[i+1]-metrow[i];
			if(metrow[i+1]-metrow[i]<minrow)
			minrow=metrow[i+1]-metrow[i];
		}
		for(int i=0;i<metcol.size()-1;i++)
		{
			if(metcol[i+1]-metcol[i]>mxcol)
			mxcol=metcol[i+1]-metcol[i];
			if(metcol[i+1]-metcol[i]<mincol)
			mincol=metcol[i+1]-metcol[i];
		}
		cout<<(metrow.size()-1)*(metcol.size()-1)<<" "<<mincol*minrow<<" "<<mxcol*mxrow<<endl;
		row.reset();
		col.reset();
		metrow.clear();
		metcol.clear();
	}
}
