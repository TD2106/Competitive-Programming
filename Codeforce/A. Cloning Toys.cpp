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
ll x,y,t;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>x>>y;
    t=y-1;
    if(t<0){
        cout<<"No\n";
        return 0;
    }
    if(t>x){
        cout<<"No\n";
        return 0;
    }
    if(t==0&&x>0){
        cout<<"No\n";
        return 0;
    }
    while(t<x) t*=3;
    if(x==t) cout<<"Yes\n";
    else {
        t/=3;
        if((x-t)%2==0){
            cout<<"Yes\n";
        }
        else cout<<"No\n";
    }
    return 0;
}
