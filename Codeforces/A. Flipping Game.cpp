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
    int n,t=0,a[100005],Ti=0,p=-1;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],Ti+=a[i];
    for(int i=1;i<=n;i++){
        if(a[i]) t--;
        else t++;
        p=max(p,t);
        if(t<0) t=0;
    }
    cout<<Ti+p<<endl;
    return 0;
}



