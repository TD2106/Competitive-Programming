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
typedef pair<pii,int> piii;
int n,m,t,Ti[100005];
vector<piii> t1,t2,ab;
stack<int> b;
int main(){
    ios_base::sync_with_stdio(0);
    fr("OVERLOAD.INP");
    fw("OVERLOAD.OUT");
    cin>>n>>m;
    up(i,1,n){
        cin>>t;
        t1.pb({{t,1},i});
    }
    up(i,1,m){
        cin>>t;
        t2.pb({{t,2},i});
    }
    ab.resize(n+m);
    merge(all(t1),all(t2),ab.begin());
    while(!ab.empty()){
        piii temp = ab[ab.size()-1];
        if(temp.fi.se==1){
            if(b.empty()) Ti[temp.se]=-1;
            else{
                Ti[temp.se]=b.top();
                b.pop();
            }
        }
        else b.push(temp.se);
        ab.pop_back();
    }
    up(i,1,n) cout<<Ti[i]<<endl;
    return 0;
}
