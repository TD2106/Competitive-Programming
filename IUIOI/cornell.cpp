#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{
	string temp;
	int n,m,testcase,sum;
	cin>>testcase;
	while(testcase--)
	{
		sum=1;
		vector<string> data;
		cin>>n>>m;
		cin.ignore();
		for(int i=0;i<n+m;i++)
		{
			cin>>temp;
			data.push_back(temp);
		}
		sort(data.begin(),data.end());
		for(int i=0;i<n+m-1;i++)
		{
			if(data[i]!=data[i+1])
			{
				sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
