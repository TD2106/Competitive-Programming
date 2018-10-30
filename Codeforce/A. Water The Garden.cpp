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
int tc,n,k,x[205]={0},Ti,l,r;
bool bed[205];
bool check(int m){
    reset(bed);
    up(i,1,k){
        up(j,x[i],min(n,x[i]+m-1)) bed[j]=1;
        down(j,x[i],max(1,x[i]-m+1)) bed[j]=1;
    }
    up(i,1,n){
        if(!bed[i]) return 0;
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>tc;
    while(tc--){
        cin>>n>>k;
        up(i,1,k) cin>>x[i];
        l=1,r=n;
        Ti=n;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid)){
                Ti=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        cout<<Ti<<endl;
    }
    return 0;
}
