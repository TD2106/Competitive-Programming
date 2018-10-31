#include <bits/stdc++.h>
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define reset(a) memset(a,0,sizeof(a))
#define all(a) a.begin(),a.end()
#define pb push_back
#define ins insert
#define mp make_pair
#define fi first
#define se second
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long int ll;
typedef unsigned long long int llu;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int main(){
    set<int> sock;
    int n,t;
    int Ti=0;
    cin>>n;
    for(int i=0;i<2*n;i++){
        cin>>t;
        if(sock.count(t)) sock.erase(t);
        else sock.insert(t);
        Ti=max(Ti,(int)sock.size());
    }
    cout<<Ti<<endl;
    return 0;
}



