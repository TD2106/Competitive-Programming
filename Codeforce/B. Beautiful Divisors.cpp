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
ll n,Ti,temp,k=1;
ll fastPow(ll base,ll k){
    ll res=1;
    while(k){
        if(k%2) res*=base;
        base*=base;
        k/=2;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    temp=1;
    cin>>n;
    while(temp<=n){
        temp=(fastPow(2,k)-1LL)*fastPow(2,k-1LL);
        if(n%temp==0) Ti=temp;
        k++;
    }
    cout<<Ti<<endl;
    return 0;
}
