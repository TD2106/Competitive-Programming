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
int n,a[200005],aSorted[200005],l=0,r=0;
string swapable;
vector<pii> canSwap;
bool vis[200005]={0};
multiset<int> ms1,ms2;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n){
        cin>>a[i];
        aSorted[i]=a[i];
    }
    cin>>swapable;
    up(i,0,swapable.size()-1){
        if(swapable[i]=='1'){
            if(l==0){
                l=i+1;
                r=i+2;
            }
            else r=i+2;
        }
        else{
            if(l!=0){
                canSwap.pb({l,r});
                l=r=0;
            }
        }
    }
    if(l!=0) canSwap.pb({l,r});
    for(pii t:canSwap){
//        cout<<t.fi<<' '<<t.se<<endl;
        up(i,t.fi,t.se) vis[i]=1;
    }
    sort(aSorted+1,aSorted+1+n);
    up(i,1,n){
        if(vis[i]==0&&a[i]!=aSorted[i]){
            cout<<"NO\n";
            return 0;
        }
    }
    for(pii t:canSwap){
        ms1.clear();
        ms2.clear();
        up(i,t.fi,t.se){
            ms1.insert(a[i]);
            ms2.insert(aSorted[i]);
        }
        if(ms1!=ms2){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}
