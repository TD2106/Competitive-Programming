#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{
	int n,check;
	cin>>n;
	vector<int> pos;
	while(n)
	{
		check=1;
		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			pos.push_back(temp);
		}
		sort(pos.begin(),pos.end());
		for(int i=0;i<n-1;i++)
		{
			if((pos[i+1]-pos[i])>200)
			{
				check=0;
				break;
			}
		}
		if((1422-pos[n-1])>100)
		check=0;
		if(check)
		cout<<"POSSIBLE"<<endl;
		else
		cout<<"IMPOSSIBLE"<<endl;
		pos.clear();
		cin>>n;
	}
	return 0;
}
