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
    int n,m,b[101],g[101],Ti=0,idxb=0,idxg=0;
    cin>>n;
    for(int i=0;i<n;i++) cin>>b[i];
    cin>>m;
    for(int i=0;i<m;i++) cin>>g[i];
    sort(b,b+n);
    sort(g,g+m);
    while(idxb<n&&idxg<m){
        if((int)abs(b[idxb]-g[idxg])<=1){
            Ti++,idxb++,idxg++;
        }
        else{
            if(b[idxb]<g[idxg]) idxb++;
            else idxg++;
        }
    }
    cout<<Ti<<endl;
    return 0;
}



