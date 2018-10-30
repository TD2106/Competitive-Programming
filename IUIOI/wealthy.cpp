#include <iostream>
#include <algorithm>
using namespace std;
struct house
{
	int street;
	int floor;
	int index;
};
bool mycmp(const house& a,const house& b)
{
	return ((a.floor>b.floor||a.street<b.street));
}
int main ()
{
	house input[30002];
	int d,h,rank[30002]={0},n,status=1,first=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>d>>h;
		input[i].index=i;
		input[i].street=d;
		input[i].floor=h;
	}	
	sort(input,input+n,mycmp);
	for(int i=0;i<n;i++)
	{
		while(input[i].floor==input[first].floor||input[i].street==input[first].street)
		{
			rank[input[i].index]=status;
			first=i;
			i++;
			if(i>=n)
			break;
		}
		first=i;
		i--;
		status++;
	}
	for(int i=0;i<n;i++)
	cout<<rank[i]<<endl;
	return 0;
}
