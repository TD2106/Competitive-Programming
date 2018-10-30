#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
struct data
{
	int num;
	string output;
};
bool dk(data lhs, data rhs){
	if (lhs.num > rhs.num) return false;
	else return true;
}

int main ()
{
	int n;
	vector<data> result;
	char inputstring[1000];
	memset(inputstring,'\0',1000);
	//freopen("482.txt","r",stdin);
	cin>>n;
	getchar();
	while(n--)
	{
		vector<int> temp1;
		vector<string> temp2;
		cin.getline(inputstring,1000);
		memset(inputstring,'\0',1000);
		cin.getline(inputstring,1000);
		char *ptr;
		int temp;
		string test;
		ptr=strtok(inputstring," ");
		while(ptr!=NULL)
		{
			sscanf(ptr,"%d",&temp);
			temp1.push_back(temp);
			ptr=strtok(NULL," ");
		}
		memset(inputstring,'\0',1000);
		cin.getline(inputstring,1000);
		ptr=strtok(inputstring," ");
		while(ptr!=NULL)
		{
			test=string(ptr);
			temp2.push_back(test);
			ptr=strtok(NULL," ");
		}
		memset(inputstring,'\0',1000);
		for(int i=0;i<temp1.size();i++)
		{
			data temp_data;
			temp_data.num=temp1[i];
			temp_data.output=temp2[i];
			result.push_back(temp_data);
		}
		sort(result.begin(), result.end(),dk);
		for(int i=0;i<temp1.size();i++)
		{
			cout<<result[i].output<<endl;
		}
		result.clear();
		cout<<endl;
	}
	return 0;
}
