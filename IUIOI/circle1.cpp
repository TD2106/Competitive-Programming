#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main ()
{
	int n;
	char temp;
	vector<string> circle;
	string s;
	cin>>n;
	cin.ignore();
	cin>>s;
	circle.push_back(s);
	for(int i=0;i<n-1;i++)
	{
		temp=s[0];
		s.erase(0,1);
		s+=temp;
		circle.push_back(s);
	}
	sort(circle.begin(),circle.end());
	for(int i=0;i<n;i++)
	cout<<circle[i]<<"\n";
	return 0;
}
