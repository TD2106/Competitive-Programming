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
int n,Ti[216107]={0};
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>Ti[i];
    for(int i=1;i<=n/2;i++){
        if(i%2){
            swap(Ti[i],Ti[n-i+1]);
        }
    }
    for(int i=1;i<=n;i++) cout<<Ti[i]<<" ";
    return 0;
}



