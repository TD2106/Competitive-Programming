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
ll dp[100005]={0},Ti=0,t;
vector<ll> a,temp;
int l,r,n,k;
void process(){
    ll res=0;
    reset(dp);
    up(i,1,a.size()) dp[i]=dp[i-1]+a[i-1];
    up(i,1,a.size()-k+1){
        if(dp[i+k-1]-dp[i-1]>res){
            res=dp[i+k-1]-dp[i-1];
            l=i;
            r=i+k-1;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    fr("PRIZES.INP");
    fw("PRIZES.OUT");
    cin>>n>>k;
    up(i,0,n-1){
        cin>>t;
        a.pb(t);
    }
    process();
    l--,r--;
    up(i,0,n-1){
        if(i>=l&&i<=r) continue;
        temp.pb(a[i]);
    }
    a=temp;
    process();
    l--,r--;
    up(i,l,r) Ti+=a[i];
    cout<<Ti<<endl;
    return 0;
}
