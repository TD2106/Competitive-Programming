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
vi p;
int a[6],t,s1=0,s2=0;
bool Ti=0;
int main(){
    ios_base::sync_with_stdio(0);
    up(i,0,5) cin>>a[i];
    up(i,0,5) p.pb(i);
    do{
        s1=s2=0;
        up(i,0,2) s1+=a[p[i]];
        up(i,3,5) s2+=a[p[i]];
        if(s1==s2) Ti=1;
    }while(next_permutation(all(p)));
    if(Ti) cout<<"YES";
    else cout<<"NO";
    return 0;
}
