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
    int l[100005],n,idx1,idx2,idx3;
    cin>>n;
    for(int i=0;i<n;i++) cin>>l[i];
    sort(l,l+n);
    for(int i=0;i<n-2;i++){
        if(l[i]+l[i+1]>l[i+2]){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}



