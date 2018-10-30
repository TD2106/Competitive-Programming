#include <iostream>
using namespace std;
bool checkcomma(string s)
{
	return (s[s.size()-1]==',');
}
bool checkperiod(string s)
{ 
	return (s[s.size() - 1]=='.'); 
}
int main ()
{
	int n;
	string word[1001],result;
	cin>>n;
	cin.ignore();
	for(int i=0;i<n;i++)
	{
		cin>>word[i];
		if(i==0)
		{
			result+=word[i];
			continue;
		}
		if(word[i]=="and"||word[i]=="or")
		{
			if(!checkcomma(word[i-1])&&checkcomma(word[i-2])&&!checkperiod(word[i-1]))
			result+=",";
			result+=" "+word[i];
		}
		else
		result+=" "+word[i];
	}
	cout<<result;
	return 0;
}
