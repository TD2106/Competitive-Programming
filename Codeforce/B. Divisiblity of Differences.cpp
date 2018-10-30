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
int cnt[100005]={0},a[100005],n,k,m,Ti=-1;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k>>m;
    up(i,1,n){
        cin>>a[i];
        cnt[a[i]%m]++;
        if(cnt[a[i]%m]==k) Ti=a[i]%m;
    }
    if(Ti==-1) cout<<"No";
    else{
        cout<<"Yes\n";
        int c=0;
        up(i,1,n){
            if(c==k) break;
            if(a[i]%m==Ti) cout<<a[i]<<' ',c++;
        }
    }
    return 0;
}
