#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
#define up(i,l,r) for(int i=l;i<=r;i++)
#define down(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
typedef long long int ll;
string s1[100005],s2[100005];
int main(){
//	ios_base::sync_with_stdio(0);
	fr("myresD.txt");
	fw("compare.txt");
	up(i,1,100000) cin>>s1[i];
	up(i,1,100000) cin>>s2[i];
	up(i,1,100000){
        if(s1[i]!=s2[i]){
            cout<<i<<" "<<s1[i]<<" "<<s2[i]<<endl;
        }
	}
	return 0;
}