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
ll n,k,a[100005]={0},Ti,mn=1e18;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    up(i,1,k){
        cin>>a[i];
        if(n%a[i]<mn){
            mn=n%a[i];
            Ti=i;
        }
    }
    cout<<Ti<<' '<<n/a[Ti]<<endl;
    return 0;
}
