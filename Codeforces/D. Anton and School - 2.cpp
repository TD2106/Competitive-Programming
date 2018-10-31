#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
string s;
ll fac[200005]={0},mod=1e9+7,Ti=0,fr[200005]={0},bk[200005]={0},n,po[200005];
ll fastpow(ll n,ll k){
    ll ans=1;
    while(k){
        if(k%2) ans*=n;
        n=n*n;
        k/=2;
        ans%=mod;
        n%=mod;
    }
    return ans%mod;
}
void precompute(ll sz){
    fac[0]=fac[1]=1;
    for(int i=2;i<=sz;i++){
        fac[i]=fac[i-1]*i;
        fac[i]%=mod;
    }
    for(int i=0;i<=sz;i++) po[i]=fastpow(fac[i],mod-2)%mod;
}

ll C(ll n,ll k){
    //cout<<n<<" "<<k<<endl;
    return (fac[n]*(po[n-k]*po[k]%mod)%mod)%mod;
}
int main(){
    cin>>s;
    n=s.size();
    precompute(n);
    for(int i=1;i<=n;i++){
        if(s[i-1]=='(') fr[i]=fr[i-1]+1;
        else fr[i]=fr[i-1];
    }
    for(int i=n;i>=1;i--){
        if(s[i-1]==')') bk[i]=bk[i+1]+1;
        else bk[i]=bk[i+1];
    }
    for(int i=1;i<=n;i++){
        if(s[i-1]=='(') Ti+=C(fr[i-1]+bk[i+1],bk[i+1]-1);
        Ti%=mod;
       // cout<<Ti<<endl;
    }
    cout<<Ti<<endl;
    return 0;
}
