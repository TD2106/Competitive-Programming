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
int n,l,r,pos,Ti=1e9;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>pos>>l>>r;
    if(l!=1&&r!=n){
        Ti=min(Ti,abs(pos-l)+1+abs(r-l)+1);
        Ti=min(Ti,abs(pos-r)+1+abs(l-r)+1);
    }
    else if(l!=1){
        Ti=min(Ti,abs(pos-l)+1);
    }
    else if(r!=n){
        Ti=min(Ti,abs(pos-r)+1);
    }
    else Ti=0;
    cout<<Ti<<endl;
    return 0;
}
