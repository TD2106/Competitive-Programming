#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
struct obj
{
	long long id;
	long long scr;
	long long incre;
};
class comp
{
	public:
		bool operator()(obj a,obj b)
		{
			return (a.incre<b.incre||a.incre==b.incre&&a.id<b.id);
		}
};
int main ()
{
	priority_queue< obj,vector<obj>,comp > data;
	obj temp;
	long long id,z,p,l,c,s,n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>id>>z>>p>>l>>c>>s;
		long long tempscr=p*50+l*5+c*10+20*s;
		temp.id=id;
		temp.scr=tempscr;
		temp.incre=tempscr-z;
		data.push(temp);
	}
	for(int i=0;i<5;i++)
	{
		cout<<data.top().id<<" "<<data.top().scr<<endl;
		data.pop();
	}
}
