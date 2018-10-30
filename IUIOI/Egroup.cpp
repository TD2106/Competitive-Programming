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
ll Ti[4][30005]={0},n,d[30005]={0},t,ans=40000;
void init(){
    for(int i=1;i<=3;i++){
        for(int j=1;j<=n;j++) Ti[i][j]=40000;
    }
    for(int i=1;i<=3;i++){
        if(i==d[1]) Ti[i][1]=0;
        else Ti[i][1]=1;
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>d[i];
    init();
    for(int i=2;i<=n;i++){
        for(int j=1;j<=3;j++){
            if(j==d[i]) t=0;
            else t=1;
            for(int k=1;k<=j;k++) Ti[j][i]=min(Ti[j][i],Ti[k][i-1]+t);
        }
    }
    for(int i=1;i<=3;i++) ans=min(Ti[i][n],ans);
    init();
    for(int i=2;i<=n;i++){
        for(int j=1;j<=3;j++){
            if(j==d[i]) t=0;
            else t=1;
            for(int k=j;k<=3;k++) Ti[j][i]=min(Ti[j][i],Ti[k][i-1]+t);
        }
    }
    for(int i=1;i<=3;i++) ans=min(Ti[i][n],ans);
    cout<<ans<<endl;
    return 0;
}



