#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{
	int temp,s=0;
	vector<int> arr;
	for(int i=0;i<9;i++)
	{
		cin>>temp;
		s=s+temp;
		arr.push_back(temp);
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<8;i++)
	{
		for(int j=i+1;j<9;j++)
		{
			if(s-arr[i]-arr[j]==100)
			{
				arr[i]=0;
				arr[j]=0;
				break;
			}
		}
		if(!arr[i])
		break;
	}
	for(int i=0;i<9;i++)
	{
		if(arr[i])
		cout<<arr[i]<<"\n";
	}
	return 0;
}
