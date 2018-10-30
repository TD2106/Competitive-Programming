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
int n,x,y,first,second;
int main(){
    ios_base::sync_with_stdio(0);
    first = second = 0;
    cin>>n;
    up(i,1,n){
        cin>>x>>y;
        if(x>0) first++;
        else second++;
    }
    if(first<=1||second<=1) cout<<"Yes";
    else cout<<"No";
    return 0;
}
