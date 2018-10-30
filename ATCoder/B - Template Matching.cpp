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
    int n,m,flag=0;
    vector<string> A;
    vector<string> B;
    string s;
    cin>>n>>m;
    A.resize(n);
    B.resize(m);
    for(int i=0;i<n;i++) cin>>A[i];
    for(int i=0;i<m;i++) cin>>B[i];
    for(int i=0;i<n-m+1;i++){
        for(int j=0;j<n-m+1;j++){
            s=A[i].substr(j,m);
            if(s==B[0]){
                flag=1;
                for(int k=1;k<m;k++){
                    s=A[i+k].substr(j,m);
                    if(s!=B[k]){
                        flag=0;
                        break;
                    }
                }
            }
        }
    }
    if(flag) cout<<"Yes";
    else cout<<"No";
    return 0;
}



