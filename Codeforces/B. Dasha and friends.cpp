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
int n,l,kefa[101]={0},sa[101]={0},dis1[101]={0},dis2[101]={0};
bool check(int st){
    int mark,idx=1;
    for(int i=st;i<=n;i++){
        if(dis1[idx]!=dis2[i]) return 0;
        else idx++;
    }
    for(int i=1;i<st;i++){
        if(dis1[idx]!=dis2[i]) return 0;
        else idx++;
    }
    return 1;
}
int main(){
    cin>>n>>l;
    for(int i=1;i<=n;i++) cin>>kefa[i];
    for(int i=1;i<=n;i++) cin>>sa[i];
    for(int i=1;i<n;i++){
        dis1[i]=kefa[i+1]-kefa[i];
        dis2[i]=sa[i+1]-sa[i];
    }
    dis1[n]=l-kefa[n]+kefa[1];
    dis2[n]=l-sa[n]+sa[1];
    for(int i=1;i<=n;i++){
        if(check(i)){
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO\n";
    return 0;
}



