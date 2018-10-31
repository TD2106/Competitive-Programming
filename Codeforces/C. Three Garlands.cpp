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
int k[3];
set<pii> mem;
int main(){
    ios_base::sync_with_stdio(0);
    up(i,0,2) cin>>k[i];
    sort(k,k+3);
    if(k[0]==1){
        cout<<"Yes\n";
        return 0;
    }
    int cur1=1,cur2=2;
    mem.insert({1,2});
    while(1){
        up(i,1,k[2]-1){
            if(i>cur1) cur1+=k[0];
            if(i>cur2) cur2+=k[1];
            if(i!=cur1&&i!=cur2){
                cout<<"No\n";
                return 0;
            }
        }
        while(cur1<k[2]) cur1+=k[0];
        while(cur2<k[2]) cur2+=k[1];
        cur1-=k[2];
        cur2-=k[2];
        if(mem.count({cur1,cur2})){
            cout<<"Yes\n";
            return 0;
        }
        else mem.insert({cur1,cur2});
    }
    return 0;
}
