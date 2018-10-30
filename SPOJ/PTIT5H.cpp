#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(char a)
{
	return (a=='*');
}
int main ()
{
	string pattern,s,pre,suf;
	int n;
	cin>>n;
	cin.ignore();
	cin>>pattern;
	string::iterator itr=find_if(pattern.begin(),pattern.end(),cmp);
	int temp=itr-pattern.begin();
	pre=pattern.substr(0,temp);
	suf=pattern.substr(temp+1);
	while(n--)
	{
		cin>>s;
		string compare1,compare2;
		if(s.size()<pre.size()+suf.size())
		{
			cout<<"NE\n";
			continue;
		}
		compare1=s.substr(0,pre.size());
		compare2=s.substr(s.size()-suf.size());
		if(compare1==pre&&compare2==suf)
		cout<<"DA\n";
		else
		cout<<"NE\n";
	}
	return 0;
}
