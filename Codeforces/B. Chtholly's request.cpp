#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
#define up(i,l,r) for(int i=l;i<=r;i++)
#define down(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
ll powerOfTen[]={1,10,100,1000,10000,100000};
ll Ti=0,p,n;
ll digit(ll x){
    ll result = 0;
    while(x){
        result++;
        x/=10;
    }
    return result;
}
ll reverseLL(ll x){
    vector<ll> t;
    while(x){
        t.pb(x%10);
        x/=10;
    }
    ll res=0,d=1;
    down(i,t.size()-1,0) res+=t[i]*d,d*=10;
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>p;
    up(i,1,n){
        Ti+=(ll)i*(powerOfTen[digit(i)])+reverseLL(i);
        Ti%=p;
    }
    cout<<Ti<<endl;
    return 0;
}
