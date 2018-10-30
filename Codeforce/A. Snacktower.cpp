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
pii a[100005];
bool cmp(pii a,pii b){
    return (a.fi>b.fi);
}
int main(){
    int n,idx=0,j;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].fi;
        a[i].se=i;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        for(j=idx;a[j].se<=i&&j<n;j++){
            cout<<a[j].fi<<" ";
        }
        idx=j;
        cout<<endl;
    }
    return 0;
}



