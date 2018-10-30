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
bool cmp(ll a, ll b){
    return a>b;
}
int main(){
    ll Ti=0,n,k,mark[26]={0};
    int idx;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        char t;
        cin>>t;
        mark[t-'A']++;
    }
    sort(mark,mark+26,cmp);
    for(int i=0;i<26&&k>0;i++){
        Ti+=pow(min(k,mark[i]),2);
        k-=min(k,mark[i]);
    }
    cout<<Ti<<endl;
    return 0;
}



