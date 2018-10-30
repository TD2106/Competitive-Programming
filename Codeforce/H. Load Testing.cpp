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
#define M 100005
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll Ti=1e18,f[M]={0},b[M]={0},n,a[M],fv[M],bv[M];
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n) cin>>a[i];
    up(i,1,n){
        if(a[i]>fv[i-1]) f[i]+=f[i-1],fv[i]=a[i];
        else f[i]+=f[i-1]+fv[i-1]+1-a[i],fv[i]=fv[i-1]+1;
    }
    down(i,n,1){
        if(a[i]>bv[i+1]) b[i]+=b[i+1],bv[i]=a[i];
        else b[i]+=b[i+1]+bv[i+1]+1-a[i],bv[i]=bv[i+1]+1;
    }
    up(i,1,n) Ti=min(Ti,f[i-1]+b[i+1]+max(max(fv[i-1],bv[i+1])+1-a[i],0LL));
    cout<<Ti<<endl;
    return 0;
}
