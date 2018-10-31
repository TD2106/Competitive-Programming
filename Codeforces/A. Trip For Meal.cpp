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
int n,a,b,c,Ti;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>a>>b>>c;
    if(n==1) Ti=0;
    else if(n==2) Ti=min(a,b);
    else{
        Ti=min(a,b)+(n-2)*min(a,min(b,c));
    }
    cout<<Ti<<endl;
    return 0;
}
