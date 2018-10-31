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
ll n,k,Ti=0,t[305],cur=0;
priority_queue< ll,vector<ll>,greater<ll> > pq;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
    up(i,1,n) cin>>t[i];
    up(i,1,k) pq.push(t[i]);
    cur+=pq.top();
    Ti+=cur;
    pq.pop();
    up(i,k+1,n){
        pq.push(t[i]);
        cur+=pq.top();
        Ti+=cur;
        pq.pop();
    }
    while(!pq.empty()){
        cur+=pq.top();
        Ti+=cur;
        pq.pop();
    }
    cout<<Ti<<endl;
	return 0;
}
