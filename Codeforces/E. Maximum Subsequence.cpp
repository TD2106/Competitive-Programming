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
vector<ll> firstHalf,secondHalf,a;
ll n,m,arr[40],Ti=0,temp;
void generateSubset(int length,vector<ll>& result){
    ll sum;
    up(i,0,(1<<length)-1){
        sum=0;
        up(j,0,length-1){
            if(i&(1<<j)) sum+=a[j];
        }
        result.pb(sum%m);
    }
    sort(all(result));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    up(i,1,n) cin>>arr[i];
    up(i,1,(n+1)/2) a.pb(arr[i]);
    generateSubset(a.size(),firstHalf);
    a.clear();
    up(i,(n+1)/2+1,n) a.pb(arr[i]);
    generateSubset(a.size(),secondHalf);
    for(ll i:firstHalf){
        temp=*(lower_bound(all(secondHalf),m-i)-1);
        Ti=max(Ti,(temp+i)%m);
        temp=*(lower_bound(all(secondHalf),2*m-i)-1);
        Ti=max(Ti,(temp+i)%m);
    }
    cout<<Ti<<endl;
    return 0;
}
