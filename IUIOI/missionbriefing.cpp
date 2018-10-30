#include <iostream>
#include <bitset>
using namespace std;
int main ()
{
	string input,str;
	bitset<10> agent;
	while(cin>>str);
	input+=str;
	int numofagent=0;
	for(int i=0;i<input.size()-2;i++)
	{
		if(input[i]=='0')
		{
			if(input[i+1]=='0')
			{
				int temp=input[i+2]-'0';
				if(temp>=1&&temp<=9)
				{
					if(!agent[temp])
					{
						agent[temp]=1;
						numofagent++;
					}
				}
			}
		}
	}
	cout<<numofagent;
	return 0;
}
