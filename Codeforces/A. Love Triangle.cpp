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
int n,a[5005];
bool check(int idx){
    int d1,d2,d3;
    d1=a[idx];
    d2=a[d1];
    d3=a[d2];
    if(d2!=idx&&d3==idx) return 1;
    else return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n) cin>>a[i];
    up(i,1,n){
        if(check(i)){
            cout<<"Yes\n";
            return 0;
        }
    }
    cout<<"No\n";
    return 0;
}
