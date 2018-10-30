#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main ()
{
	int N;
	cin>>N;
	int temp;
	vector<int> arr;
	for(int i=0;i<N;i++)
	{
		cin>>temp;
		arr.push_back(temp);
	}
	for(int i=0;i<4*N;i++)
	cin>>temp;
	sort(arr.begin(),arr.end());
	for(int i=0;i<N;i++)
	cout<<arr[i]<<endl;
	return 0;
}
