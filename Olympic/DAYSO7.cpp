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
typedef vector<int> vi;
typedef pair<int,int> pii;
ll Ti=-1e18,l[200005],r[200005],n,a[200005],sum[200005]={0};
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    l[0]=r[n+1]=0;
    up(i,3,n) l[i]=max(sum[i]-sum[i-3]+l[i-3],sum[i]-sum[i-3]);
    up(i,4,n) l[i]=max(l[i],l[i-1]);
    down(i,n-2,1) r[i]=max(sum[i+2]-sum[i-1]+r[i+3],sum[i+2]-sum[i-1]);
    down(i,n-3,1) r[i]=max(r[i],r[i+1]);
    up(i,3,n-3) Ti=max(Ti,l[i]+r[i+1]);
    cout<<Ti<<endl;
    return 0;
}
