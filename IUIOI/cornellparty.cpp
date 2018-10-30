#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int cntcor[1000001],cntwhi[1000001];
bool cmpC(int a,int b)
{
	return (cntcor[a]<cntcor[b]);
}
bool cmpW(int a,int b)
{
	return (cntwhi[a]<cntwhi[b]);
}
int main ()
{
	int tc,n,temp;
	vector<int> cornell,white;
	cin>>tc;
	while(tc--)
	{
		memset(cntcor,0,sizeof(cntcor));
		memset(cntwhi,0,sizeof(cntwhi));
		cornell.clear();
		white.clear();
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			if(cntcor[temp]==0)
			cornell.push_back(temp);
			cntcor[temp]++;
		}
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			if(cntwhi[temp]==0)
			white.push_back(temp);
			cntwhi[temp]++;
		}
		bool check=1;
		if(cornell.size()!=white.size())
		check=0;
		else
		{
			sort(cornell.begin(),cornell.end(),cmpC);
			sort(white.begin(),white.end(),cmpW);
			for(int i=0;i<cornell.size();i++)
			{
				if(cntcor[cornell[i]]!=cntwhi[white[i]])
				{
					check=0;
					break;
				}
			}
		}
		if(check)
		cout << "what a lovely party\n";
		else
		cout << "you've messed up, Cornell\n";
	}
	return 0;
}
