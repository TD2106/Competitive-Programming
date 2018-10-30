#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct door
{
	int value;
	int index;
};
bool mycompare(const door& a, const door& b)
{
	return a.value<b.value;
}
int main ()
{
	vector<int> henchman;
	vector<door> input;
	door temporary;
	int n,m,temp,henchindex=0,doorindex=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		henchman.push_back(temp);
	}
	for(int i=0;i<m;i++)
	{
		cin>>temp;
		temporary.value=temp;
		temporary.index=i;
		input.push_back(temporary);
	}
	sort(henchman.begin(),henchman.end());
	sort(input.begin(),input.end(),mycompare);
	for(int i=0;i<m-1;i++)
	{
		while(doorindex<m&&input[doorindex].index<=i)
		doorindex++;
		while(henchindex<n&&henchman[henchindex]<input[doorindex].value)
		henchindex++;
		cout<<henchindex<<endl;
	}
	cout<<n<<endl;
	return 0;
}
