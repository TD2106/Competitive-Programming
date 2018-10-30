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
int n,t,Ti;
bool isNPrime[1000005]={0};
int main(){
    ios_base::sync_with_stdio(0);
    memset(isNPrime,1,sizeof(isNPrime));
    for(ll i=2;i*i<=1e6;i++){
        if(isNPrime[i]){
            for(ll j=i*i;j<=1e6;j+=i) isNPrime[j]=0;
        }
    }
    cin>>n;
    up(i,1,n){
        cin>>t;
        Ti=max(max(isNPrime[t],isNPrime[t-1]),isNPrime[t+1]);
        cout<<Ti<<endl;
    }
    return 0;
}
