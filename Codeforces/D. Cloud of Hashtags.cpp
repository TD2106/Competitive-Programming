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
string ht[500001];
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++) cin>>ht[i];
    for(int i=n-2;i>=0;i--){
        if(ht[i]<=ht[i+1]) continue;
        else{
            for(int j=0;j<ht[i].size();j++){
                if(ht[i][j]>ht[i+1][j]){
                    ht[i].resize(j);
                    break;
                }
            }
        }

    }
    for(int i=0;i<n;i++) cout<<ht[i]<<endl;
    return 0;
}



