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
int n,m,Ti[200005]={0},pos[200005]={0},e;
bool cmp(int a,int b){
    return (pos[a]>pos[b]);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    up(i,1,n){
        Ti[i]=i;
        pos[i]=(n-i+1);
    }
    up(i,1,m){
        cin>>e;
        pos[e]=n+i;
    }
    sort(Ti+1,Ti+1+n,cmp);
    up(i,1,n) cout<<Ti[i]<<endl;
    return 0;
}
