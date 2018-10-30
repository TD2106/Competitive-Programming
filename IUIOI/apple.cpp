#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <cstdio>
using namespace std;
int main ()
{
	bitset<2001> mark;
	int n,k;
	cin>>n>>k;
	vector<float> arr;
	int count=1;
	arr.push_back((float)n);
	while(k--)
	{
		cout << "Count : " << count << endl;
		for(int i=0;i<count;i++)
		{
			
			if(ceil(arr[0])==arr[0])
			{
				int temp1,temp2;
				float temp;
				temp=arr[0]*2-1;
				temp1=(int)temp;
				temp2=(int)arr[0];
				cout << "1: " << temp1 << " ";
				if(!mark[temp1])
				{
					arr.push_back(arr[0]-0.5);
					mark[temp1]=1;
				}
				cout << " 2" << endl;
				if(!mark[temp2])
				{
					arr.push_back(arr[0]/2.0);
					mark[temp2]=1;
				}
			}
			else
			{
				float temp=arr[0]*2-1;
				if(!mark[(int)temp])
				{
					arr.push_back(arr[0]-0.5);
					mark[(int)temp]=1;
				}
			}
			arr.erase(arr.begin());
			
		}
		count=arr.size();
		mark.reset();
	}
	sort(arr.begin(),arr.end());
	cout<<arr.size()<<endl;
	for(int i=0;i<arr.size()-1;i++)
	printf("%.1f ",arr[i]);
	printf("%.1f",arr[arr.size()-1]);
	return 0;
}
