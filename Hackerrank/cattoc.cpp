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
ll b,n,Ti,tc,m[1005],l,r,serving,mnTime;
ll check(ll x){
    ll total=0;
    up(i,1,b) total+=(x+m[i]-1)/m[i];
    return total;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>tc;
    while(tc--){
        cin>>b>>n;
        up(i,1,b) cin>>m[i];
        l=1,r=1e15;
        mnTime=1e15;
        serving=1e15;
        while(l<=r){
            ll mid=(l+r)/2;
            if(check(mid)>=n){
                serving=min(serving,check(mid));
                mnTime=min(mnTime,mid);
                r=mid-1;
            }
            else l=mid+1;
        }
        serving-=n;
        down(i,b,1){
            if((mnTime-1)%m[i]==0){
                if(serving==0){
                    Ti=i;
                    break;
                }
                else serving--;
            }
        }
        cout<<Ti<<endl;
    }
    return 0;
}
