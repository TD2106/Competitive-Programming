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
ll n,k,t,Ti[10000005]={0},mn[10000005]={0},mx=0;
int main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>t;
        Ti[t]++;
        mx=max(t,mx);
    }
    for(int i=mx;i>=1;i--){
        if(Ti[i]){
             mn[(i+1)/2]+=Ti[i];
             Ti[i/2]+=Ti[i];
             Ti[(i+1)/2]+=Ti[i];
        }
        Ti[i]+=Ti[i+1];
        Ti[i]-=mn[i];
        if(Ti[i]>=k){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}



