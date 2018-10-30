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
#define M 200005
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
vector<vi> Ti;
int n,a;
set<pii> s;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n){
        cin>>a;
        auto itr=s.lower_bound({a,0});
        if(itr==s.begin()){
            vi temp;
            temp.pb(a);
            Ti.pb(temp);
            s.insert({a,Ti.size()-1});
        }
        else{
            itr--;
            pii temp=*itr;
            Ti[temp.se].pb(a);
            s.erase(*itr);
            s.insert({a,temp.se});
        }
    }
    for(auto v:Ti){
        for(auto i:v) cout<<i<<' ';
        cout<<endl;
    }
    return 0;
}
