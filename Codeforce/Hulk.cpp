#include <iostream>
#include <vector>
using namespace std;
int main ()
{
	vector<string> str;
	string temp="I love ";
	str.push_back(temp);
	temp="I hate ";
	str.push_back(temp);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(i==n)
		cout<<str[i%2]<<"it";
		else
		cout<<str[i%2]<<"that ";
	}
	return 0;
}
