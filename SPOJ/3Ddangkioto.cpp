#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool mycompare (int a,int b)
{
	return (a>b);
}
int main ()
{
	int n,array[100001],a,b,time=0,index=0;
	vector<int> phandu;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>array[i];
	}
	cin>>a>>b;
	for(int i=0;i<n;i++)
	{
		phandu.push_back(a%array[i]);
	}
	sort(phandu.begin(),phandu.end(),mycompare);
	if(phandu[0]==0)
	{
		cout<<a-b;
		return 0;
	}
	while(a>=b)
	{
		while((a-phandu[index])>=b)
		{
			a-=phandu[index];
			time++;
			cout<<a<<" "<<time<<endl;
		}
		index++;
		if(phandu[index]==0)
		break;
	}
	if(a!=b)
	time+=(a-b);
	cout<<time;
	return 0;\
}
