#include <iostream>
#include <string>
using namespace std;
int main ()
{
	string s;
	while(cin>>s)
	{
		bool palin=1;
		for(int i=0;i<s.size()/2;i++)
		{
			if(s[i]!=s[s.size()-1-i])
			{
				palin=0;
				break;
			}
		}
		if(palin)
		{
			cout<<s<<endl;
			continue;
		}
		int i,j;
		for(i=1;i<s.size();i++)
		{
			palin=1;
			int temp=i;
			j=s.size()-1;
			if(s[i]!=s[j])
			continue;
			else
			{
				while(i>=j)
				{
					i++;
					j--;
					if(s[i]!=s[j])
					{
						palin=0;
						break;
					}
				}
			}
			if(palin)
			{
				i=temp;
				break;
			}
		}
		i--;
		string suf;
		for(int j=i;j>=0;j--)
		suf+=s[j];
		cout<<s+suf;
	}
	return 0;
}
