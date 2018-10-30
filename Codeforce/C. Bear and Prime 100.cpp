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
int Ti=0;
string s;
vi prime;
int main(){
    ios_base::sync_with_stdio(0);
    up(i,2,100){
        if(prime.size()==16) break;
        bool flag=1;
        up(j,2,i-1){
            if(i%j==0) flag=0;
        }
        if(flag) prime.pb(i);
    }
    prime.pb(4);
    prime.pb(9);
    prime.pb(25);
    prime.pb(49);
    for(int i:prime){
        cout<<i<<endl;
        cin>>s;
        if(s=="yes") Ti++;
    }
    if(Ti<=1) cout<<"prime";
    else cout<<"composite";
    fflush(stdout);
    return 0;
}
