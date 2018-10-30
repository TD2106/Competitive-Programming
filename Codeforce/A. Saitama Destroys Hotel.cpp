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

int main(){
    int n,s,Ti=0,pre;
    pii pas[101];
    cin>>n>>s;
    pre=s;
    for(int i=0;i<n;i++){
        cin>>pas[i].fi>>pas[i].se;
    }
    sort(pas,pas+n,greater<pii>());
    for(int i=0;i<n;i++){
        Ti+=pre-pas[i].fi;
        pre=pas[i].fi;
        if(pas[i].se>=Ti) Ti=pas[i].se;
    }
    Ti+=pre-0;
    cout<<Ti<<endl;
    return 0;
}



