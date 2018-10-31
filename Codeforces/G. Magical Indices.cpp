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
#define MX 1000000
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
int tc,n,Ti=0,a[1000005],mx[1000005],mn[1000005];
int main(){
    ios_base::sync_with_stdio(0);
    cin>>tc;
    while(tc--){
        Ti=0;
        cin>>n;
        up(i,1,n) cin>>a[i];
        mx[1]=a[1];
        up(i,2,n) mx[i]=max(a[i],mx[i-1]);
        mn[n]=a[n];
        down(i,n-1,1) mn[i]=min(a[i],mn[i+1]);
        up(i,2,n-1){
            if(mx[i-1]<=a[i]&&mn[i+1]>=a[i]) Ti++;
        }
        cout<<Ti<<endl;
    }
    return 0;
}
