#include <iostream>
#include <stack>
using namespace std;
int main ()
{
	int q,com,price,temp;
	stack<int> food;
	cin>>q;
	while(q--)
	{
		cin>>com;
		if(com==1)
		{
			if(food.empty())
			cout<<"No Food\n";
			else
			{
				temp=food.top();
				cout<<temp<<endl;
				food.pop();
			}
		}
		else
		{
			cin>>price;
			food.push(price);
		}
	}
	return 0;
}
