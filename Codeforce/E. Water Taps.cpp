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
ll n,a[200005],t[200005],x;
double Ti=0,cnt[1000005]={0},temp1;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>x;
    up(i,1,n) cin>>a[i];
    up(i,1,n) cin>>t[i];
    up(i,1,n) cnt[t[i]]+=a[i];
    Ti+=cnt[x];
    for(int l=x-1,r=x+1;l!=0&&r!=1e6+1;){
        while((cnt[l]==0||cnt[r]==0)&&l!=0&&r!=1e6+1){
            if(cnt[l]==0) l--;
            else r++;
        }
        if(l!=0&&r!=1e6+1){
            temp1 = cnt[r]*(x-r)*1.0/(l-x);
            if(temp1<=cnt[l]){
                Ti+=temp1+cnt[r];
                cnt[r]=0;
                cnt[l]-=temp1;
            }
            temp1 = cnt[l]*(l-x)*1.0/(x-r);
            if(temp1<=cnt[r]){
                Ti+=temp1+cnt[l];
                cnt[l]=0;
                cnt[r]-=temp1;
            }
        }
    }
    cout<<fixed<<setprecision(10)<<Ti<<endl;
    return 0;
}
