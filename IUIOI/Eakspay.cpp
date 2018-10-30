#include <iostream>
#include <sstream>
#include <string>
using namespace std;
string process(string &temp)
{
	int first=1;
	string piglatin,head;
	if(temp[0]=='a'||temp[0]=='u'||temp[0]=='i'||temp[0]=='e'||temp[0]=='o'||temp[0]=='y')
	{
		piglatin=temp+"yay ";
	}
	else
	{
		for(int i=0;i<temp.size();i++)
		{
			if(temp[i]=='a'||temp[i]=='u'||temp[i]=='i'||temp[i]=='e'||temp[i]=='o'||temp[i]=='y')
			first++;
			if(first==1)
			head+=temp[i];
			else
			piglatin+=temp[i];
		}
		piglatin=piglatin+head+"ay ";
	}
	return piglatin;
}
void splitstring (string &s)
{
	istringstream split;
	split.str(s);
	string temp,result;
	while(split>>temp)
	{
		result+=process(temp);
	}
	cout<<result<<endl;
	return ;
}
int main ()
{
//	freopen("input","r",stdin);
	string s;
	int testcase;
	cin>>testcase;
	cin.ignore();
	while(testcase--)
	{
		getline(cin,s);
		splitstring(s);
	}
	return 0;
}
