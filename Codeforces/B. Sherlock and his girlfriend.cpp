#include <bits/stdc++.h>
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define reset(a) memset(a,0,sizeof(a))
#define all(a) a.begin(),a.end()
#define pb push_back
#define ins insert
#define mp make_pair
#define fi first
#define se second
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long int ll;
typedef unsigned long long int llu;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
int n,t,co=2;
vi prime,temp;
bool mark[100005]={0};
map<vi,int> storevalue;
int main(){
    cin>>n;
    for(ll i=2;i*i<=n+1;i++){
        if(!mark[i]){
            for(ll j=i*i;j<=n+1;j+=i) mark[j]=1;
        }
    }
    if(n<=2) cout<<1<<endl;
    else cout<<2<<endl;
    for(ll i=2;i<=n+1;i++){
        if(mark[i]) cout<<2<<" ";
        else cout<<1<<" ";
    }

    return 0;
}



