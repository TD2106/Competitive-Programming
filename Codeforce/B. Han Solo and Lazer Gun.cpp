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
int gcd(int a,int b){
    if(a*b==0) return a+b;
    else return gcd(b,a%b);
}
int main(){
    set<pii> mark;
    int n,x0,y0,x,y,t1,t2,tgcd;
    cin>>n>>x0>>y0;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        t1=x-x0;
        t2=y-y0;
        if(t1<0) t1=-t1,t2=-t2;
        else if(t1*t2==0){
            t1=abs(t1);
            t2=abs(t2);
        }
        tgcd=abs(gcd(t1,t2));
        t1/=tgcd;
        t2/=tgcd;
        mark.insert(mp(t1,t2));
    }
    cout<<mark.size()<<endl;
    return 0;
}



