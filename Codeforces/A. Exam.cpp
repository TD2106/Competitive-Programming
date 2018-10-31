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
    int n;
    cin>>n;
    if(n==1||n==2) cout<<1<<endl<<1<<endl;
    else if(n==3) cout<<2<<endl<<"1 3"<<endl;
    else if(n==4) cout<<4<<endl<<"3 1 4 2"<<endl;
    else{
        cout<<n<<endl;
        for(int i=1;i<=n;i+=2) cout<<i<<" ";
        for(int i=2;i<=n;i+=2) cout<<i<<" ";
    }
    return 0;
}



