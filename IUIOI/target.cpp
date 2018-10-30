#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
bool compare(int i, int j)
{
	return (i>j);
}
int main ()
{
	int N,M,x,y,hittime[100000]={0};
	cin>>N>>M;
	int temp;
	unsigned long long min=0,max=0;
	double distance;
	vector<int> ring;
	vector<int> point;
	vector<int>::iterator up;
	for(int i=0;i<N;i++)
	{
		cin>>temp;
		ring.push_back(temp);
	}
	for(int i=0;i<N;i++)
	{
		cin>>temp;
		point.push_back(temp);
	}
	sort(point.begin(),point.end(),compare);
	for(int i=0;i<M;i++)
	{
		cin>>x>>y;
		distance=sqrt(pow(x,2)+pow(y,2));
		temp=(int)ceil(distance);
		up=upper_bound(ring.begin(),ring.end(),temp);
		if(up==ring.end())
		continue;
		else
		{
			if(up==ring.begin())
			hittime[up-ring.begin()]++;
			else if(*(up-1)==temp)
			{
				up--;
				hittime[up-ring.begin()]++;
			}
			else
			hittime[up-ring.begin()]++;	
		}
	}
	sort(hittime,hittime+100000,compare);
	temp=0;
	while(hittime[temp])
	{
		max+=hittime[temp]*point[temp];
		min+=hittime[temp]*point[N-1-temp];
		temp++;
	}
	cout<<min<<"\n"<<max;
	return 0;
}
