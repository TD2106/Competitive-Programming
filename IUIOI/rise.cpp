#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main ()
{
	int n,temp,sumva=0,sumzom=0;
	vector<int> zom,vam;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		if(temp%2)
		{
			sumva+=temp;
			vam.push_back(temp);
		}
		else
		{
			sumzom+=temp;
			zom.push_back(temp);
		}
	}
	sort(zom.begin(),zom.end());
	sort(vam.begin(),vam.end());
	for(int i=0;i<zom.size();i++)
	cout<<zom[i]<<" ";
	cout<<sumzom<<" ";
	for(int i=0;i<vam.size();i++)
	cout<<vam[i]<<" ";
	cout<<sumva;
	return 0;
}
