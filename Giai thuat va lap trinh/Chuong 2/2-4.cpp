#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main ()
{
	int n,k;
	cin>>n;
	cin>>k;
	cin.ignore();
	vector<string> s;
	for(int i=0;i<n;i++)
	{
		string temp;
		getline(cin,temp);
		s.push_back(temp);
	}
	int mang[k];
	for(int i=0;i<k;i++)
	{
		mang[i]=i;
		cout<<s[mang[i]]<<" ";
	}
	cout<<endl;
	int check;
	while(1)
	{
		check=1;
		for(int i=k-1;i>=0;i--)
		{
			if(mang[i]!=n-k+i)
			{
				check=0;
				mang[i]=mang[i]+1;
				for(int j=i+1;j<k;j++)
				mang[j]=mang[j-1]+1;
				break;
			}
		}
		if(check)
		break;
		for(int i=0;i<k;i++)
		{
			cout<<s[mang[i]]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
