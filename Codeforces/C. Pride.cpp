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
int n,a[2005],gcd[2005][2005]={0},Ti=0,mn=1e9,ones=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n) cin>>a[i];
    up(i,1,n){
        int temp=0;
        up(j,i,n){
            gcd[i][j]=__gcd(temp,a[j]);
            temp=gcd[i][j];
            if(gcd[i][j]==1) mn=min(mn,j-i+1);
        }
    }
    if(gcd[1][n]!=1) Ti=-1;
    else Ti=mn-1+n-1;
    if(mn==1){
        up(i,1,n) if(a[i]==1) ones++;
        Ti=n-ones;
    }
    cout<<Ti<<endl;
    return 0;
}
