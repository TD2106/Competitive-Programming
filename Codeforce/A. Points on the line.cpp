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
int n,d,x[105]={0},Ti=1e9,t,mn=1e9,mx=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>d;
    up(i,1,n){
        cin>>t;
        x[t]++;
        mn=min(t,mn);
        mx=max(t,mx);
    }
    if(mx-mn<=d){
        cout<<0<<endl;
        return 0;
    }
    up(i,1,100) x[i]+=x[i-1];
    up(i,1,100){
        if(i+d<=100) Ti=min(Ti,n-(x[i+d]-x[i-1]));
        Ti=min(Ti,n-(x[i]-x[i-1]));
    }
    cout<<Ti<<endl;
    return 0;
}
