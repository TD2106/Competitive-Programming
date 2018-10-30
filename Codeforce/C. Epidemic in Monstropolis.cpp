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
int a[501],b[501],sum[501]={0},n,k,st=1,en,sumb=0;
vpii pos;
bool checkPos(int l,int r){
    if(r-l+1==1) return 1;
    if(r-l+1==2&&a[l]!=a[r]) return 1;
    for(int i=l+1;i<=r;i++){
        if(a[i]!=a[i-1]) return 1;
    }
    return 0;
}
void process(int st,int l,int r){
    if(l-r+1==1) return;
    int idx,t=0,ptr;
    for(int i=l;i<=r;i++){
        if(a[i]>t){
            t=a[i];
            idx=i;
        }
    }
    if(idx==l&&a[idx]==a[idx+1]){
        for(int i=idx;i<=r;i++)
        if(a[i]==a[idx]&&a[i]>a[i+1]){
            idx=i;
            break;
        }
    }
    ptr=st+idx-l;
    if(idx==r){
        for(int i=r;i>=l+1;i--) cout<<ptr--<<" L\n";
        return ;
    }
    else{
        if(a[idx]>a[idx+1]){
            for(int i=idx+1;i<=r;i++) cout<<ptr<<" R\n";
            for(int i=idx;i>=l+1;i--) cout<<ptr--<<" L\n";
            return ;
        }
        else{
            cout<<ptr--<<" L\n";
            for(int i=idx+1;i<=r;i++) cout<<ptr<<" R\n";
            for(int i=idx;i>=l+2;i--) cout<<ptr--<<" L\n";
            return ;
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]+=sum[i-1]+a[i];
    }
    cin>>k;
    for(int i=1;i<=k;i++) cin>>b[i],sumb+=b[i];
    if(sumb!=sum[n]){
        cout<<"NO\n";
        return 0;
    }
    for(int i=1;i<=k;i++){
        for(int j=st;j<=n;j++){
            if(sum[j]-sum[st-1]==b[i]){
                en=j;
                break;
            }
        }
        if(checkPos(st,en)){
            pos.pb(mp(st,en));
            st=en+1;
        }
        else{
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    if(pos.size()!=k){
        cout<<"NO\n";
        return 0;
    }
    for(int i=0;i<k;i++) process(i+1,pos[i].fi,pos[i].se);
    return 0;
}



