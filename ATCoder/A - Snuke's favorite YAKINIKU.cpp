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
string s,Ti;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>s;
    if(s.size()<4) cout<<"No\n";
    else{
        Ti=s.substr(0,4);
        if(Ti=="YAKI") cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
