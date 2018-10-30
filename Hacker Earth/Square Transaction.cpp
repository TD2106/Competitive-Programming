#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main ()
{
	int t,temp,q,que;
	vector<int> sum;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>temp;
		if(!i)
		sum.push_back(temp);
		else
		sum.push_back(temp+sum[i-1]);
	}
	cin>>q;
	while(q--)
	{
		cin>>que;
		vector<int>::iterator itr=lower_bound(sum.begin(),sum.end(),que);
		if(itr==sum.end())
		cout<<"-1\n";
		else
		cout<<itr-sum.begin()+1<<endl;
	}
	return 0;
}
