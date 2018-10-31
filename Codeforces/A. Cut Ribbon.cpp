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
    int n,a,b,c,Ti[4001]={0};
    cin>>n>>a>>b>>c;
    for(int i=1;i<=n;i++){
        if(a<=i&&(Ti[i-a]!=0||i-a==0)) Ti[i]=max(Ti[i],1+Ti[i-a]);
        if(b<=i&&(Ti[i-b]!=0||i-b==0)) Ti[i]=max(Ti[i],1+Ti[i-b]);
        if(c<=i&&(Ti[i-c]!=0||i-c==0)) Ti[i]=max(Ti[i],1+Ti[i-c]);
    }
    cout<<Ti[n]<<endl;
    return 0;
}



