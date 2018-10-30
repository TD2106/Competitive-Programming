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
typedef pair< ll,pair<ll,ll> > plll;
ll n,s,Ti=0,sumA=0,sumB=0,pizzaA,pizzaB,t1=0,t2=0;
vector<plll> eatA,eatB;
class Compare{
public:
    bool operator()(const plll& lhs,const plll& rhs){
        return (abs(lhs.se.fi-lhs.se.se)>abs(rhs.se.fi-rhs.se.se));
    };
};
ll calculate(ll sum,ll pizza,const vector<plll>& v){
    priority_queue<plll,vector<plll>,Compare> pq;
    ll t=0;
    for(auto temp:v) pq.push(temp);
    sum-=pizza;
    while(sum){
        plll temp = pq.top();
        pq.pop();
        if(sum>=temp.fi){
            t+=temp.fi*abs(temp.se.fi-temp.se.se);
            sum-=temp.fi;
        }
        else{
            t+=sum*abs(temp.se.fi-temp.se.se);
            sum=0;
        }
    }
    return t;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>s;
    up(i,1,n){
        plll temp;
        cin>>temp.fi>>temp.se.fi>>temp.se.se;
        if(temp.se.fi>temp.se.se) eatA.pb(temp),sumA+=temp.fi;
        else eatB.pb(temp),sumB+=temp.fi;
    }
    if(sumA%s==0||sumB%s==0||((sumA%s+sumB%s)>s)){
        for(auto temp:eatA) Ti+=temp.fi*temp.se.fi;
        for(auto temp:eatB) Ti+=temp.fi*temp.se.se;
    }
    else{
        pizzaA=sumA/s*s;
        pizzaB=sumB/s*s;
        for(auto temp:eatA) Ti+=temp.fi*temp.se.fi;
        for(auto temp:eatB) Ti+=temp.fi*temp.se.se;
//        bug(sumA);
//        bug(sumB);
//        bug(pizzaA);
//        bug(pizzaB);
        t1=calculate(sumA,pizzaA,eatA);
        t2=calculate(sumB,pizzaB,eatB);
        Ti=max(Ti-t1,Ti-t2);
    }
    cout<<Ti<<endl;
    return 0;
}
