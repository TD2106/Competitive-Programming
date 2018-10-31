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
typedef pair<ll,ll> pll;
struct line{
    ll a,b,c;
    line(ll aa,ll bb,ll cc){
        this -> a = aa;
        this -> b = bb;
        this -> c = cc;
    }
    line(){}
    line(ll x,ll y,const pll& point){
        this->a=x;
        this->b=y;
        c=-a*point.fi-b*point.se;
    }
    line(const pll& p1,const pll& p2){
        this->a=-(p2.se-p1.se);
        this->b=p2.fi-p1.fi;
        c=-a*p1.fi-b*p1.se;
    }
    bool isOnTheLine(const pll& point){
        return ((a*point.fi+b*point.se+c)==0);
    }

};
bool vis[1005];
pll points[1005];
line l1,l2;
int n;
bool Ti=0;
bool check(const pll& a,const pll& b){
    reset(vis);
    bool flag=0;
    l1=line(a,b);
    up(i,1,n){
        vis[i]=l1.isOnTheLine(points[i]);
        if(!vis[i]) l2=line(l1.a,l1.b,points[i]),flag=1;
    }
    if(!flag) return 0;
    up(i,1,n) vis[i]=vis[i]|l2.isOnTheLine(points[i]);
    up(i,1,n){
        if(!vis[i]) return 0;
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n) cin>>points[i].se,points[i].fi=i;
    Ti=Ti|check(points[1],points[2]);
    Ti=Ti|check(points[1],points[3]);
    Ti=Ti|check(points[2],points[3]);
    if(Ti) cout<<"Yes";
    else cout<<"No";
    return 0;
}
