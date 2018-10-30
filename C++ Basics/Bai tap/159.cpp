#include <iostream>
#include <vector>
using namespace std;
int main ()
{
	int n,s;
	cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++)
	a.push_back(1);
	for(int i=0;i<n;i++)
	{
		if(i==n-1)
		cout<<a[i]<<"="<<n<<endl;
		else
		cout<<a[i]<<"+";
	}
	a.clear();
	for(int i=2;i<n;i++)
	{
		a.clear();
		a.push_back(i);
		for(int j=1;j<=n-i;j++)
		a.push_back(1);
		for(int j=0;j<a.size();j++)
	    {
		    if(j==a.size()-1)
		    cout<<a[j]<<"="<<n<<endl;
		    else
		    cout<<a[j]<<"+";
	    }
	    int j=1;
		while(1)
		{
			
			if(a[j]==i)
			j++;
			s=0;
			a[j]=a[j]+1;
			a.pop_back();
			for(int k=0;k<a.size();k++)
			s=s+a[k];
			if(s!=n)
			break;
			for(int k=0;k<a.size();k++)
	        {
		        if(k==a.size()-1)
		        cout<<a[k]<<"="<<n<<endl;
		        else
		        cout<<a[k]<<"+";
	        }
		}
	}
	return 0;
}
