#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int main ()
{
	int m,cnt=0;
	cin>>m;
	cin.ignore();
	while(m--)
	{
		stack<char> arch;
		string s;
		cin>>s;
		for(int i=0;i<s.size();i++)
		{
			if(arch.empty()||arch.top()!=s[i])
			arch.push(s[i]);
			else
			arch.pop();
		}
		if(arch.empty())
		cnt++;
	}
	cout<<cnt;
	return 0;
}
