#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define MOD 1000000007
using namespace std;
typedef long long int ll;
string s;
ll hashS[200005],hashR[200005]={0},Ti=0,n,k,pow33[200005]={0};
ll fastPow(ll base,ll power){
    ll res=1;
    while(power){
        if(power%2) res*=base;
        base*=base;
        power/=2;
        res%=MOD;
        base%=MOD;
    }
    return res;
}
void precompute(){
    ll res=1;
    pow33[0]=1;
    for(int i=1;i<=n;i++){
        res*=33;
        res%=MOD;
        pow33[i]=fastPow(res,MOD-2);
    }
}
ll calHashInterval(int i,int j){
    ll res=(hashS[j]-hashS[i-1]+MOD)%MOD;
    res=(res*pow33[i-1])%MOD;
    return res;
}
ll calHashIntervalRev(int i,int j){
    ll res=(hashR[i]-hashR[j+1]+MOD)%MOD;
    res=(res*pow33[n-j])%MOD;
    return res;
}
ll binarySearchOdd(ll idx){
    ll l=1,r=2*min(idx,n-idx+1),res=0;
    r--;
    while(l<=r){
        ll mid=(l+r)/2;
        if(!(mid%2)) mid--;
        if(calHashInterval(idx-mid/2,idx+mid/2)==calHashIntervalRev(idx-mid/2,idx+mid/2)){
            res=max(res,mid);
            l=mid+2;
        }
        else r=mid-2;
    }
    return res;
}
ll binarySearchEven(ll idx1,ll idx2){
    ll l=2,r=2*min(idx1,n-idx2+1),res=0;
    while(l<=r){
        ll mid=(l+r)/2;
        if(mid%2) mid--;
        if(calHashInterval(idx1-mid/2+1,idx2+mid/2-1)==calHashIntervalRev(idx1-mid/2+1,idx2+mid/2-1)){
            res=max(res,mid);
            l=mid+2;
        }
        else r=mid-2;
    }
    return res;
}
int main(){
	ios_base::sync_with_stdio(0);
    cin>>s;
    n=s.size();
    precompute();
    k=1;
    for(int i=1;i<=n;i++){
        hashS[i]=(s[i-1]-'a')*k+hashS[i-1];
        k*=33;
        k%=MOD;
        hashS[i]%=MOD;
    }
    k=1;
    for(int i=n;i>=1;i--){
        hashR[i]=(s[i-1]-'a')*k+hashR[i+1];
        k*=33;
        k%=MOD;
        hashR[i]%=MOD;
    }
    for(int i=1;i<=n;i++){
        Ti+=binarySearchOdd(i)/2;
    }
    for(int i=1;i<=n-1;i++){
        if(s[i-1]==s[i]){
            Ti+=binarySearchEven(i,i+1)/2;
        }
    }
    Ti=n*(n+1)/2+1-Ti;
    cout<<Ti<<endl;
	return 0;
}
