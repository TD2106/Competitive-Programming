#include <iostream>
#include <vector>
using namespace std;
int main ()
{
	string s1,s2;
	cout<<"Nhap chuoi s1 dai hon ";
	getline(cin,s1);
	cout<<"Nhap chuoi s2 ngan hon ";
	getline(cin,s2);
	int j=0,check=1;
	vector<int> a;
	for(int i=0;i<s1.size();i++)
	{
		check = 1;
		if(s1[i]==s2[j])
		{
			j++;
			check=0;
			
		}
		if(check)
		a.push_back(i);
	}
	check=0;
	if(j==s2.size())
	{
		for(int i=0;i<a.size();i++)
		{
			s1.erase(a[i]-check,1);
			check++;
		}
		cout<<s1;
	}
	else
	cout<<"Ko dc theo yeu cau de bai";
	return 0;
}
