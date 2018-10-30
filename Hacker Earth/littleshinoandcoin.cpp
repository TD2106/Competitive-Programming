#include <iostream>
#include <bitset>
using namespace std;
int main ()
{
	bitset<1000> mark;
	int k,sum,total=0;
	cin>>k;
	cin.ignore();
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		for(int j='a';j<='z';j++)
		mark[j]=0;
		sum=0;
		for(int j=i;j<s.size();j++)
		{
			if(!mark[s[j]])
			{
				sum++;
				mark[s[j]]=1;
			}
			if(sum==k)
			total++;
			if(sum>k)
			break;
		}
	}
	cout<<total;
	return 0;
}
