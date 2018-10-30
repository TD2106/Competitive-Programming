#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main ()
{
	int n,column,length,row;
	char arr[4];
	string temp,line="------------------------------------------------------------";
	vector<string> data;
	//freopen("400.txt","r",stdin);
	while(scanf("%s",&arr)!=EOF)
	{
		sscanf(arr,"%d",&n);
		cin.ignore();
		int max=0;
		for(int i=0;i<n;i++)
		{
			getline(cin,temp);
			if(temp.size()>max)
			max=temp.size();
			data.push_back(temp);
		}
		sort(data.begin(),data.end());
		column=1+(60-max)*1.0/(max+2);
		length=max+2;
		row=ceil(n*1.0/column);
		cout<<line<<"\n";
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<column;j++)
			{
				if(i+j*row<n)
				{
					if(j!=column-1)
					{
						cout<<data[i+j*row];
						for(int k=0;k<length-data[i+j*row].size();k++)
						cout<<" ";
					}
					else
					cout<<data[i+j*row];
				}
			}
			cout<<"\n";
		}
		data.clear();
	}
	return 0;
}
