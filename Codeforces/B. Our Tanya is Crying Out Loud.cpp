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
ll n,k,Ti=0,a,b,t;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k>>a>>b;
    t=n;
    if(k==1){
        cout<<(n-1)*a<<endl;
        return 0;
    }
    while(n!=1){
        if(n/k>=1) Ti+=(n%k)*a,n-=n%k,Ti+=min(b,a*(n-n/k)),n/=k;
        else Ti+=a*(n-1),n=1;
    }
    Ti=min(Ti,(t-1)*a);
    cout<<Ti<<endl;
    return 0;
}
