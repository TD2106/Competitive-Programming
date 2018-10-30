#include <iostream>
#include <queue>
using namespace std;
int main ()
{
	long long tich,n,temp;
	priority_queue<int> data;
	cin>>n;
	while(n--)
	{
		cin>>temp;
		data.push(temp);
		if(data.size()<3)
		{
			cout<<-1<<endl;
			continue;
		}
		tich=1;
		long long x,y,z;
		x=data.top();
		data.pop();
		y=data.top();
		data.pop();
		z=data.top();
		data.pop();
		tich=x*y*z;
		cout<<tich<<endl;
		data.push(x);
		data.push(y);
		data.push(z);
	}
	return 0;
}
