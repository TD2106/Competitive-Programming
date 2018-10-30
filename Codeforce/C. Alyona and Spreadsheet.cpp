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
    int n,m,k,l,r,t=0,mx=0,Ti[100005]={0},idx;
    vector<vi> arr;
    cin>>n>>m;
    arr.resize(n+1);
    for(int i=0;i<=n;i++){
        arr[i].resize(m+1);
        if(i==0) for(int j=1;j<=m;j++) arr[i][j]=-1;
        else for(int j=1;j<=m;j++) cin>>arr[i][j];
    }
    for(int j=1;j<=m;j++){
        mx=idx=1;
        for(int i=1;i<=n;i++){
            if(i==n){
                Ti[i]=n;
                continue;
            }
            if(i>=idx) idx=i+1,mx=i;
            while(idx<=n){
                if(arr[idx-1][j]<=arr[idx][j]) mx=max(mx,idx),idx++;
                else break;
            }
            Ti[i]=max(Ti[i],mx);
            //cout<<j<<" "<<i<<" "<<mx<<" "<<Ti[i]<<endl;
        }
    }
    for(int i=1;i<=n;i++) Ti[i]=max(Ti[i-1],Ti[i]);
    //for(int i=1;i<=n;i++) cout<<Ti[i]<<" ";
    cin>>k;
    while(k--){
        cin>>l>>r;
        if(r<=Ti[l]) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}



