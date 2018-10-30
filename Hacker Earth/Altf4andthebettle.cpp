#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
struct obj
{
	long long time;
	long long what;
};
bool cmp(obj a,obj b)
{
	return (a.time<b.time||a.time==b.time&&a.what<b.what);
}
int main ()
{
	ios::sync_with_stdio(false);
	long long a,b,c,n,tc,ans,res;
	vector<obj> input;
	cin>>tc;
	while(tc--)
	{
		res=-1;
		obj temp;
		cin>>n>>a>>b>>c;
		for(int i=1;i<=n;i++)
		{
			cin>>temp.time;
			temp.what=1;
			input.push_back(temp);
			cin>>temp.time;
			temp.what=2;
			input.push_back(temp);
		}
		ans=n*a;
		sort(input.begin(),input.end(),cmp);
		for(int i=0;i<input.size();i++)
		{
			if(input[i].what==1)
			ans+=(b-a);
			else
			ans+=(c-b);
			res=max(res,ans);
		}
		cout<<res<<endl;
		input.clear();
	}
	return 0;
}
