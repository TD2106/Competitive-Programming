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
ll len[51]={0},n,r,l,Ti=0,t;
vll mod2;
void precompute(){
    t=2;
    for(int i=0;i<=50;i++) len[i] = t - 1,t*=2;
}
int calBit(ll idx,ll p){
    //cout<<len[p]<<endl;
    if(idx==len[p]/2+1) return p;
    else if(idx>len[p]/2+1) return calBit(idx-(len[p]/2+1),p-1);
    else return calBit(idx,p-1);
}
int div2(ll i){
    int ans=0;
    while(i) ans++,i/=2;
    return ans-1;
}
int main(){
    cin>>n>>l>>r;
    precompute();
    t=n;
    //for(int i=0;i<=50;i++) cout<<len[i]<<endl;
    if(n==0){
        cout<<0<<endl;
        return 0;
    }
    else{
        while(t) mod2.pb(t%2),t/=2;
        reverse(all(mod2));
        //cout<<l<<" "<<r<<endl;
        //cout<<mod2.size()<<endl;
        for(ll i=l;i<=r;i++){
            t=div2(i);
            //cout<<i<<" "<<t<<" "<<pow(2,t)<<endl;
            Ti+=mod2[calBit(i,t)];
        }
        cout<<Ti<<endl;
    }
    return 0;
}



