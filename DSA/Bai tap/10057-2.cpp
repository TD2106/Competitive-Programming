#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{
	int temp,n,min,possible,dem;
	char arr[10];
	//freopen("10057.txt","r",stdin);
	vector<int> arrayint;
	while(cin>>n)
	{
		int count[70000]={0};
		dem=0;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			count[temp]++;
			arrayint.push_back(temp);
		}
		sort(arrayint.begin(),arrayint.end());
		if(n%2)
		{
			min=arrayint[n/2];
			possible=1;
			cout<<min<<" "<<count[min]<<" "<<possible<<"\n";
		}
		else
		{
			min=arrayint[n/2-1];
			int max=arrayint[n/2];
			for(int i=min;i<=max;i++)
			{
				dem=dem+count[i];
			}
			cout<<min<<" "<<dem<<" "<<max-min+1<<"\n";
		}
		arrayint.clear();
	}
	return 0;
}
