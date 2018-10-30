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
int n,k,a[100005],Ti,mx=-2e9,mn=2e9,m1[100005],m2[100005];
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    up(i,1,n){
        cin>>a[i];
        mx=max(a[i],mx);
        mn=min(a[i],mn);
    }
    if(k==1) Ti=mn;
    else if(k>=3) Ti=mx;
    else{
        up(i,1,n){
            if(i==1) m1[i]=a[i];
            else m1[i]=min(m1[i],m1[i-1]);
        }
        down(i,n,1){
            if(i==n) m2[i]=a[i];
            else m2[i]=min(m2[i],m2[i+1]);
        }
        Ti=-2e9;
        up(i,1,n-1) Ti=max(Ti,max(m1[i],m2[i+1]));
    }
    cout<<Ti<<endl;
    return 0;
}
