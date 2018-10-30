#include <bits/stdc++.h>
#define bug(x) cout<<#x<<'='<<x<<'\n'
#define tc() int tc;cin>>tc;for(int _tc=0;_tc<tc;++_tc)
#define up(i,l,r) for(int i=l;i<=r;++i)
#define down(i,r,l) for(int i=r;i>=l;--i)
#define fw(file) freopen(file,"w",stdout)
#define fr(file) freopen(file,"r",stdin)
#define reset(x) memset(x,0,sizeof(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
int tc,n,mx=200000,le,cntFront,cntBack,ans;
string s;
ll pre[200005],suf[200005],BIT[200005];
void update(int idx,ll x){
    while(idx<=mx){
        BIT[idx]+=x;
        idx+=idx&(-idx);
    }
}
ll query(int idx){
    ll res=0;
    while(idx>0){
        res+=BIT[idx];
        idx-=idx&(-idx);
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);

}
