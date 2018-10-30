#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
int main ()
{
	fstream data;
	int C,N,sum,grade;
	float result;
	vector<float> percent;
	freopen("AVERAGE.INP","r",stdin);
	cin>>C;
	while(C--)
	{
		sum=0;
		cin>>N;
		int temp=N;
		while(N--)
		{
			cin>>grade;
			if(grade>=50)
			sum++;
		}
		result=sum*1.0/temp;
		percent.push_back(result*100);
	}
	freopen("AVERAGE.OUT","w",stdout);
	for(int i=0;i<percent.size();i++)
	{
		printf("%.3f\n",percent[i]);
	}
	return 0;
}
