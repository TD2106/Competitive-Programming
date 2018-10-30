#include <iostream>
#include <vector>
using namespace std;
int main ()
{
	vector<int> can;
	int temp,n,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		if(temp==0&&can.size()!=0)
		can.pop_back();
		else if(temp!=0)
		can.push_back(temp);
	}
	for(int i=0;i<can.size();i++)
	sum+=can[i];
	cout<<sum;
	return 0;
}
