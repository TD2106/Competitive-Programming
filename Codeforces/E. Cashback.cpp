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
ll n,c,a[100005]={0},sum=0,dpl[100005]={0},dpr[100005]={0};
multiset<ll> ms;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>c;
    up(i,1,n) cin>>a[i];
    if(c>n){
        up(i,1,n) sum+=a[i];
        cout<<sum<<endl;
        return 0;
    }
    if(c==1){
        cout<<0<<endl;
        return 0;
    }
    up(i,1,c-1){
        sum+=a[i];
        dpl[i]=sum;
        ms.insert(a[i]);
    }
    up(i,c,n){
        sum+=a[i];
        ms.insert(a[i]);
        ll temp = *(ms.begin());
        dpl[i]=min(dpl[i-1]+a[i],dpl[i-c]+sum-temp);
        sum-=a[i-c+1];
        auto itr = ms.find(a[i-c+1]);
        ms.erase(itr);
    }
    cout<<dpl[n]<<endl;
    return 0;
}
