#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
vector< map<int,int> > data;
bool check(int a,int b)
{
	int count=0;
	for(int i=0;i<5;i++)
	{
		if(data[i][a]<data[i][b])
		count++;
	}
	if(count>=3)
	return true;
	else
	return false;
}
int main ()
{
	map<int,int> input;
	vector<int> array;
	int n,temp;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		array.push_back(temp);
		input[temp]=i;
	}
	data.push_back(input);
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>temp;
			input[temp]=j;
		}
		data.push_back(input);
	}
	sort(array.begin(),array.end(),check);
	for(int i=0;i<n;i++)
	cout<<array[i]<<"\n";
	return 0;
}
