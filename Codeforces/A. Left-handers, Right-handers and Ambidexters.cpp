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
int l,r,a,Ti=0,temp;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>l>>r>>a;
    temp = min(l,r);
    Ti+=2*temp;
    l-=temp;
    r-=temp;
    temp = min(max(l,r),a);
    Ti+=2*temp;
    a-=temp;
    Ti+=a/2*2;
    cout<<Ti<<endl;
    return 0;
}
