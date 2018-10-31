#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
char st,en;
int n;
map<char,int> mp;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>st>>en>>n;
	n%=4;
	mp['v']=0,mp['<']=1,mp['^']=2,mp['>']=3;
	if((mp[st]+n)%4==mp[en]&&(mp[st]-n+4)%4==mp[en]) cout<<"undefined";
	else if((mp[st]+n)%4==mp[en]) cout<<"cw";
	else if((mp[st]-n+4)%4==mp[en]) cout<<"ccw";
	else cout<<"undefined";
	return 0;
}
