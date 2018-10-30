#include <iostream>
#include <stack>
using namespace std;
int main ()
{
	stack<int> player;
	int tc,id,n;
	char com;
	cin>>tc;
	while(tc--)
	{
		while(!player.empty()) player.pop();
		cin>>n>>id;
		player.push(id);
		for(int i=0;i<n;i++)
		{
			cin>>com;
			if(com=='P')
			{
				cin>>id;
				player.push(id);
			}
			else
			{
				int one,two;
				one=player.top();
				player.pop();
				two=player.top();
				player.pop();
				player.push(one);
				player.push(two);
			}
		}
		cout<<"Player "<<player.top()<<endl;
	}
	return 0;
}
