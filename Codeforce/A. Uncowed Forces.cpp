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
    ll m[5]={0},w[5]={0},h1,h2,Ti=0,t=500;
    for(int i=0;i<5;i++) cin>>m[i];
    for(int i=0;i<5;i++) cin>>w[i];
    cin>>h1>>h2;
    for(int i=1;i<=5;i++){
        t=500*i;
        Ti+=(ll)max(3*t/10,(250-m[i-1])*t/250-50*w[i-1]);
    }
    Ti+=h1*100-h2*50;
    cout<<Ti<<endl;
    return 0;
}



