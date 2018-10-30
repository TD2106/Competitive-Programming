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
vector<int> Ti;
int n;
int sumDigit(int x){
    int res=0;
    while(x){
        res+=x%10;
        x/=10;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    down(i,min(81,n),1){
        if(sumDigit(n-i)==i){
            Ti.pb(n-i);
        }
    }
    cout<<Ti.size()<<endl;
    for(int i:Ti) cout<<i<<' ';
    return 0;
}
