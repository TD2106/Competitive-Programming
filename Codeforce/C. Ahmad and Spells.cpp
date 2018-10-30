#include<bits/stdc++.h>
#define bug(x) cout<< #x <<" = "<<x<<endl
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define up(i,l,r) for(int i=l;i<=r;i++)
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pll,pii> pllii;

ll n,k,m,Ti=0,x,s,tc,best[100005],temp;
vector<pll> potion,hero;
vector<pll>::iterator itr;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>tc;
    while(tc--){
        cin>>n>>m>>k>>x>>s;
        Ti=n*x;
        potion.clear();
        hero.clear();
        potion.resize(m+1);
        hero.resize(k+1);
        potion[0]=mp(0,x);
        hero[0]=(mp(0,0));
        up(i,1,m) cin>>potion[i].se;
        up(i,1,m) cin>>potion[i].fi;
        up(i,1,k) cin>>hero[i].se;
        up(i,1,k) cin>>hero[i].fi;
        sort(all(potion));
        sort(all(hero));
        up(i,0,k){
            if(i==0) best[i]=hero[i].se;
            else best[i]=max(best[i-1],hero[i].se);
        }
        up(i,0,m){
            if(potion[i].fi>s) break;
            temp=potion[i].se;
            itr=lower_bound(all(hero),mp(s-potion[i].fi+1LL,0LL));
            itr--;
            Ti=min(Ti,(n-best[itr-hero.begin()])*temp);
        }
        up(i,0,m){
            if(i==0) best[i]=potion[i].se;
            else best[i]=min(potion[i].se,best[i-1]);
        }
        up(i,0,k){
            if(hero[i].fi>s) break;
            temp=hero[i].se;
            itr=lower_bound(all(potion),mp(s-hero[i].fi+1LL,0LL));
            itr--;
            Ti=min(Ti,(n-temp)*best[itr-potion.begin()]);
        }
        cout<<Ti<<endl;
    }
}
