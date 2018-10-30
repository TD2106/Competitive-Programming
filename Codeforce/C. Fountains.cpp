#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define reset(x) memset(x,0,sizeof(x))
#define M 100005
using namespace std;
typedef long long int ll;
vector< pair<int,int> > diamond,coin;
vector< pair<int,int> >::iterator itr;
pair<int,int> t;
int n,c,d,Ti=0,best[M]={0},secondbest[M],t1,t2;
char dc;
void solve(vector< pair<int,int> > &v,int m){
    reset(best);
    reset(secondbest);
    for(int i=1;i<v.size();i++){
        if(v[i].S>v[best[i-1]].S) best[i]=i;
        else best[i]=best[i-1];
        if(best[i]==i) secondbest[i]=best[i-1];
        else{
            if(v[i].S>v[secondbest[i-1]].S) secondbest[i]=i;
            else secondbest[i]=secondbest[i-1];
        }
    }
    for(int i=1;i<v.size();i++){
        if(v[i].F>m) return;
        else{
            t1=t2=0;
            t1=v[best[i]].S;
            itr=upper_bound(v.begin(),v.end(),mp(m-v[i].F,M));
            itr--;
            if(best[(itr-v.begin())]==best[i]) t2=v[secondbest[(itr-v.begin())]].S;
            else t2=v[best[(itr-v.begin())]].S;
            if(t1!=0&&t2!=0) Ti=max(Ti,t1+t2);
        }
    }
}
int main(){
    cin>>n>>c>>d;
    diamond.pb(mp(0,0));
    coin.pb(mp(0,0));
    for(int i=0;i<n;i++){
        cin>>t.S>>t.F>>dc;
        if(dc=='C') coin.pb(t);
        else diamond.pb(t);
    }
    sort(diamond.begin(),diamond.end());
    sort(coin.begin(),coin.end());
    t1=t2=0;
    itr=upper_bound(diamond.begin(),diamond.end(),mp(d,M));
    itr--;
    for(int i=0;i<=(itr-diamond.begin());i++) t1=max(t1,diamond[i].S);
    itr=upper_bound(coin.begin(),coin.end(),mp(c,M));
    itr--;
    for(int i=0;i<=(itr-coin.begin());i++) t2=max(t2,coin[i].S);
    if(t1!=0&&t2!=0) Ti=t1+t2;
    solve(diamond,d);
    solve(coin,c);
    cout<<Ti<<endl;
	return 0;
}
