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
ll n,v[100005]={0},t[100005]={0},day[100005]={0},Ti[100005]={0};
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n) cin>>v[i];
    up(i,1,n){
        cin>>t[i];
        t[i]+=t[i-1];
    }
    up(i,1,n){
        ll temp = lower_bound(t+i,t+n+1,v[i]+t[i-1]) - (t);
        day[i] = temp;
        Ti[i]+=1;
        Ti[day[i]]-=1;
    }
    up(i,1,n) Ti[i]+=Ti[i-1];
    up(i,1,n) Ti[i]=Ti[i]*(t[i]-t[i-1]);
    up(i,1,n){
        ll temp = v[i]-(t[day[i]-1]-t[i-1]);
        Ti[day[i]]+=temp;
    }
    up(i,1,n) cout<<Ti[i]<<' ';
    return 0;
}
