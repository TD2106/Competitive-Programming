#include <iostream>
#include <map>
using namespace std;
int main ()
{
	map<int,int> data;
	int n,temp;
	cin>>n;
	while(n--)
	{
		cin>>temp;
		data[temp]++;
	}
	for(map<int,int>::iterator itr=data.begin();itr!=data.end();itr++)
	{
		if(itr->second%2)
		{
			cout<<itr->first;
			break;
		}
	}
	return 0;
}
