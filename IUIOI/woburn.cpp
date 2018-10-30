#include <iostream>
#include <vector>
using namespace std;
int main ()
{
	int mark[3]={0};
	vector<string> color;
	string temp;
	temp="RED";
	color.push_back(temp);
	temp="BLUE";
	color.push_back(temp);
	temp="WHITE";
	color.push_back(temp);
	for(int i=0;i<2;i++)
	{
		getline(cin,temp);
		for(int j=0;j<3;j++)
		{
			if(temp==color[j])
			mark[j]=1;
		}
	}
	for(int i=0;i<3;i++)
	if(mark[i]==0)
	cout<<color[i];
	return 0;
}
