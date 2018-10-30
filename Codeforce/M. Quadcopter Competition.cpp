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
int xa,ya,xb,yb,Ti;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>xa>>ya>>xb>>yb;
    if(xa<xb) Ti+=2*(xb+1-xa);
    else if(xa>xb) Ti+=2*(xa-(xb-1));
    else Ti+=4;
    if(ya<yb) Ti+=2*(yb+1-ya);
    else if(ya>yb) Ti+=2*(ya-(yb-1));
    else Ti+=4;
    cout<<Ti<<endl;
    return 0;
}
