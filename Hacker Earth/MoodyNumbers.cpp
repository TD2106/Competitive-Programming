#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
bool vis[1000]={0},isMoody[1000]={0},answer;
ll F(ll n){
    n*=n;
    ll ans=0;
    while(n) ans+=(n%10),n/=10;
    return ans;
}
bool process(ll n){
    //cout<<n<<endl;
    if(vis[n]) return isMoody[n];
    else{
         vis[n]=1;
         return isMoody[n] = process(F(n));
    }
}
int main (){
    ios_base::sync_with_stdio(false);
    int tc,Ti;
    vis[1]=vis[2]=vis[4]=vis[3]=1;
    isMoody[1]=isMoody[2]=isMoody[4]=1;
    for(int i=1;i<=200;i++) isMoody[i]=process(i);
    //process(9);
    cin>>tc;
    while(tc--){
        cin>>Ti;
        //Ti=F(Ti);
        if(Ti>200) Ti=F(Ti);
        if(isMoody[Ti]) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
