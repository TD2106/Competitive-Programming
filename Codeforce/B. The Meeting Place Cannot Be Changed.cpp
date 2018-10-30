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
int n;
pair<double,double> f[60005];
double l=0,r=2e9,Ti,pre=0;
bool check(double t){
    double ri,le=-1e9;
    ri=f[0].fi+f[0].se*t;
    le=f[n-1].fi-f[n-1].se*t;
    for(int i=1;i<n-1;i++){
        ri=min(ri,f[i].fi+f[i].se*t);
        le=max(le,f[i].fi-f[i].se*t);
    }
    if(ri>=le) return 1;
    else return 0;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>f[i].fi;
    for(int i=0;i<n;i++) cin>>f[i].se;
    sort(f,f+n);
    Ti=(l+r)/2;
    while(abs(Ti-pre)>0.000001){
        //cout<<Ti<<" "<<check(Ti)<<endl;
        if(check(Ti)) r=Ti;
        else l=Ti;
        pre = Ti;
        Ti=(l+r)/2;
        //cout<<l<<" "<<r<<endl;
        //cout<<Ti<<endl;
    }
    cout<<fixed<<setprecision(7)<<Ti<<endl;
    return 0;
}
