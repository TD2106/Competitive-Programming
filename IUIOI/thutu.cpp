#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main ()
{
	vector<int> arrayint;
	char num;
	int temp,index[3];
	for(int i=0;i<3;i++)
	{
		cin>>temp;
		arrayint.push_back(temp);
	}
	sort(arrayint.begin(),arrayint.end());
	cin.ignore();
	for(int i=0;i<3;i++)
	{
		cin>>num;
		index[i]=num-65;
	}
	cout<<arrayint[index[0]]<<" "<<arrayint[index[1]]<<" "<<arrayint[index[2]];
	return 0;
}
