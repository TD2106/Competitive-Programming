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
ll n,a[200005]={0},closestSquareRoot[200005],sq=0,Ti=0,temp;
bool isSquare[200005]={0};
vector<ll> change;
ll findClosestSquareRoot(ll x){
    ll l=0,r=1e5,res=0;
    while(l<=r){
        ll mid=(l+r)/2;
        if(mid*mid<=x){
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n){
        cin>>a[i];
        temp=findClosestSquareRoot(a[i]);
        if(temp*temp==a[i]){
            isSquare[i]=1;
            sq++;
        }
        closestSquareRoot[i]=temp;
    }
    if(sq==n-sq){
        cout<<0<<endl;
        return 0;
    }
    if(sq>n-sq){
        up(i,1,n){
            if(isSquare[i]){
                if(a[i]==0) temp=2;
                else temp=1;
                change.pb(temp);
            }
        }
        sort(all(change));
        for(ll t:change){
            if(sq==n/2) break;
            Ti+=t;
            sq--;
        }
    }
    else{
        up(i,1,n){
            if(!isSquare[i]){
                temp=min(a[i]-closestSquareRoot[i]*closestSquareRoot[i],(closestSquareRoot[i]+1)*(closestSquareRoot[i]+1)-a[i]);
                change.pb(temp);
            }
        }
        sort(all(change));
        for(ll t:change){
            if(sq==n/2) break;
            Ti+=t;
            sq++;
        }
    }
    cout<<Ti<<endl;
    return 0;
}
