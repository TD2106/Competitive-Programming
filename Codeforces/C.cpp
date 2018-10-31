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
ll tc,n,a,ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>tc;
    while(tc--)
    {
        cin>>a>>n;
        ans=0;
        if(a%n==0){
            cout<<0<<endl;
            continue;
        }
        up(i,0,63){
            if(((a>>i)&1)^(((n>>i)&1))){
                ans|=(1<<i);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
