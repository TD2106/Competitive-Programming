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
#define mod 1000000007
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
int n,k,Ti=0;
string s;
set<ll> st[30005];
map<ll,int> cnt;
ll hashString[30005][35]={0},pow33[35]={0},t;
ll fastPow(ll base,ll expo){
    ll res=1;
    base%=mod;
    while(expo){
        if(expo%2==1) res*=base;
        base*=base;
        expo/=2;
        res%=mod;
        base%=mod;
    }
    return res%mod;
}
void precompute(){
    pow33[0]=1;
    ll x=1;
    up(i,1,30){
        x*=33;
        x%=mod;
        pow33[i]=fastPow(x,mod-2);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    fr("GENE.INP");
    fw("GENE.OUT");
    precompute();
    cin>>n>>k;
    up(i,1,n){
        cin>>s;
        t=1;
        up(j,0,29){
            ll temp = s[j]-'A';
            hashString[i][j+1]=(hashString[i][j]+(temp*t)%mod)%mod;
            t*=33;
            t%=mod;
//            cout<<hashString[i][j+1]<<' '<<t<<endl;
        }
    }
    down(i,30,1){
        cnt.clear();
        up(j,1,n){
            st[j].clear();
            up(l,1,30-i+1){
                t=hashString[j][l+i-1]-hashString[j][l-1]+mod;
                t%=mod;
                t*=pow33[l-1];
                t%=mod;
                st[j].insert(t);
            }
            for(auto it:st[j]){
                cnt[it]++;
                if(cnt[it]>=k){
                    Ti=i;
                    cout<<Ti<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
