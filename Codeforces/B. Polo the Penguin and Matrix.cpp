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
int n,m,a[10005],d,Ti=0,t;
int main(){
    cin>>n>>m>>d;
    for(int i=0;i<n*m;i++) cin>>a[i];
    t=a[0]%d;
    for(int i=1;i<n*m;i++){
        if(a[i]%d!=t){
            cout<<-1<<endl;
            return 0;
        }
    }
    sort(a,a+n*m);
    t=n*m/2;
    for(int i=0;i<n*m;i++) Ti+=abs(a[t]-a[i])/d;
    cout<<Ti<<endl;
    return 0;
}



