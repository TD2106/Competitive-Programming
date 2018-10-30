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
int tc,n,a[100005],nxt[100005],bit[100005];
ll Ti,pow2[21]={0};
void precompute(){
    pow2[0]=1;
    up(i,1,20) pow2[i]=pow2[i-1]*2;
}
int main(){
    ios_base::sync_with_stdio(0);
    precompute();
    cin>>tc;
    while(tc--){
        cin>>n;
        bit[n+1]=0;
        nxt[n+1]=n;
        Ti=0;
        up(i,1,n) cin>>a[i];
        up(j,0,20){
            up(i,1,n){
                if((a[i]>>j)&1) bit[i]=1;
                else bit[i]=0;
            }
            down(i,n,1){
                if(bit[i]==1&&bit[i+1]==0) nxt[i]=i+1;
                else if(bit[i]==1&&bit[i+1]==1) nxt[i]=nxt[i+1];
            }
            up(i,1,n){
                if(bit[i]) Ti+=pow2[j]*(nxt[i]-i);
            }
        }
        cout<<Ti<<endl;
    }
    return 0;
}
