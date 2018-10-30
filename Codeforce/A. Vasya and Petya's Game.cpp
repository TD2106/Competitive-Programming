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
bool mark[1001]={0};
vi prime,Ti;
int n,idx=0,p;
int main(){
    for(int i=2;i<=1000;i++){
        if(!mark[i]){
            prime.pb(i);
            for(int j=i*i;j<=1000;j+=i) mark[j]=1;
        }
    }
    cin>>n;
    while(prime[idx]<=n&&idx<prime.size()){
        p=prime[idx];
        while(p<=n){
            Ti.pb(p);
            p*=prime[idx];
        }
        idx++;
    }
    cout<<Ti.size()<<endl;
    for(int i=0;i<Ti.size();i++) cout<<Ti[i]<<" ";
    return 0;
}



