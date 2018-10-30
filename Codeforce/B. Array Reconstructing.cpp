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
int tc,n,m,Ti[1005],idx;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>tc;
    while(tc--){
        cin>>n>>m;
        up(i,1,n) cin>>Ti[i];
        up(i,1,n){
            if(Ti[i]!=-1){
                idx=i;
                break;
            }
        }
        up(i,idx+1,n) Ti[i]=(Ti[i-1]+1)%m;
        down(i,idx-1,1) Ti[i]=(Ti[i+1]-1+m)%m;
        up(i,1,n) cout<<Ti[i]<<' ';
        cout<<endl;
    }
    return 0;
}
