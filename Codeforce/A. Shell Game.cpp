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
    int n,x,ans[3];
    cin>>n>>x;
    n%=6;
    if(n==1) ans[0]=1,ans[1]=0,ans[2]=2;
    else if(n==2) ans[0]=1,ans[1]=2,ans[2]=0;
    else if(n==3) ans[0]=2,ans[1]=1,ans[2]=0;
    else if(n==4) ans[0]=2,ans[1]=0,ans[2]=1;
    else if(n==5) ans[0]=0,ans[1]=2,ans[2]=1;
    else ans[0]=0,ans[1]=1,ans[2]=2;
    cout<<ans[x]<<endl;
    return 0;
}



