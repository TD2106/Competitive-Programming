#include <iostream>
#include <string>
#include <vector>
using namespace std;
int gcd(int a,int b)
{
	while(a*b!=0)
	{
		if(a>b)
		a=a-b;
		if(a<=b)
		b=b-a;
	}
	return a+b;
}
string taostring(int a, int b)
{
	string s="*/*";
	s[0]='0'+a;
	s[2]='0'+b;
	return s;
}
int main ()
{
	vector <string> phanso;
	vector <float> giatri;
	for(int i=2;i<=7;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(gcd(i,j)==1)
			{
				giatri.push_back(j*1.0/(i*1.0));
			    phanso.push_back(taostring(j,i));
			}
		}
	}
	string s;
	for(int i=0;i<phanso.size()-1;i++)
	{
		for(int j=i+1;j<phanso.size();j++)
		{
			if(giatri[j]<giatri[i])
			{
				float temp;
	            temp=giatri[j];
	            giatri[j]=giatri[i];
	            giatri[i]=temp;
				s=phanso[i];
				phanso[i].erase(0,3);
				phanso[i]=phanso[j];
				phanso[j].erase(0,3);
				phanso[j]=s;
				s.erase(0,3);
			}
		}
	}
	for(int i=0;i<phanso.size();i++)
	{
		if(i==phanso.size()-1)
		cout<<phanso[i];
		else
		cout<<" "<<phanso[i]<<" < ";
	}
	return 0;
}
