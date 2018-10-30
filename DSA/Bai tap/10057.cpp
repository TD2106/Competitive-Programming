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
		dem=0;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			arrayint.push_back(temp);
		}
		sort(arrayint.begin(),arrayint.end());
		if(n%2)
		{
			min=arrayint[n/2];
			possible=1;
			for(int i=0;i<n;i++)
			if(arrayint[i]==min)
			dem++;
			cout<<min<<" "<<dem<<" "<<possible<<"\n";
		}
		else
		{
			min=arrayint[n/2-1];
			int max=arrayint[n/2];
			for(int i=0;i<n;i++)
			{
				if(arrayint[i]>=min&&arrayint[i]<=max)
				dem++;
			}
			cout<<min<<" "<<dem<<" "<<max-min+1<<"\n";
		}
		arrayint.clear();
	}
	return 0;
}
