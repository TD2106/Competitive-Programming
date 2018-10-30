#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
string a,b;
bool palind(string s)
{
	return (s==string(s.rbegin(),s.rend()));
}
void solve()
{
	b="";
	getline(cin,b);
	//cout << palind(a) << ' ' << palind(b) << '\n';
	string prea="",preb="";
	if (palind(a) xor palind(b))
	{
		return;
	}
	if (a==b)
	{
		cout << "No solution.";
		return;
	}
	string res="";
	for (int i=0; i<max(a.size(),b.size()); i++)
	{
		if (i<a.size())
		{
			prea=a[i]+prea;
			if (palind(a+prea) xor palind(b+prea))
			{
				res=prea;
			}
		}
		if (i<b.size())
		{
			preb=b[i]+preb;
			if (palind(a+preb) xor palind(b+preb))
			{
				if (res=="") res=preb;
				else
					res=min(res,preb);
			}
		}
		if (res!="")
		{
			cout << res;
			return;
		}
	}
	if (a.size()>b.size())
	{
		string t=a;
		a=b;
		b=t;
	}
	string reva="";
	for (int i=0; i<a.size(); i++)
		reva=a[i]+reva;
	for (char p='a'; p<='z'; p++)
		if (palind(a+p+reva) xor palind(b+p+reva))
		{
			if (res=="") res=p+reva;
			else
			res=min(res,p+reva);
		}
	if (a.size()==b.size())
	{
		string revb="";
		for (int i=0; i<b.size(); i++)
			revb=a[i]+revb;
		for (char p='a'; p<='z'; p++)
			if (palind(a+p+revb) xor palind(b+p+revb))
			{
				if (res=="") res=p+revb;
				else
				res=min(res,p+revb);
			}
	}
	if (res!="")
	{
		cout << res;
		return;
	}
	cout << "No solution.";
}
int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.inp","r",stdin);
	//freopen("output.out","w",stdout);
	bool f=false;
	while (getline(cin,a))
		{
			if (f) cout << '\n';
			f=true;
			solve();
		}
	cout << '\n';
	return 0;
}