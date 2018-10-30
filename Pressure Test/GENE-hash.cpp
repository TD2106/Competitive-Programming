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
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
ll h[30005][35]={0},pow33[35],MOD=1e9+7,t;
int n,k,Ti=-1;
string s;
set<ll> st;
map<ll,int> cnt;
ll fastPow(ll base,ll e){
//    cout<<base<<' '<<e<<endl;
    ll res=1;
    while(e){
        if(e%2) res*=base;
        base*=base;
        e/=2;
        base%=MOD;
        res%=MOD;
//        cout<<res<<' '<<e<<endl;
    }
    return res;
}
void precompute(){
    ll res=1;
    pow33[0]=1;
    for(int i=1;i<=30;i++){
        res*=33;
        res%=MOD;
        pow33[i]=fastPow(res,MOD-2);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
//    fr("GENE.INP");
//    fw("GENE.OUT");
    precompute();
    cin>>n>>k;
    up(i,1,n){
        cin>>s;
        t=1;
        up(j,1,30){
            ll temp = s[j-1]-'A';
            h[i][j]=(h[i][j-1]%MOD+((temp*t)%MOD))%MOD;
            t*=33;
            t%=MOD;
            h[i][j]%=MOD;
            cout<<h[i][j]<<' '<<t<<endl;
        }
    }
    down(i,30,1){
        cnt.clear();
        up(j,1,n){
            st.clear();
            up(l,1,30-i+1){
                t=(h[j][l+i-1]-h[j][l-1]+MOD)%MOD;
                t=(t*pow33[l-1])%MOD;
                st.insert(t);
            }
            for(auto it:st){
                cnt[it]++;
                if(cnt[it]>=k){
                    Ti=i;
                    break;
                }
            }
            if(Ti!=-1) break;
        }
        if(Ti!=-1) break;
    }
    cout<<Ti<<endl;
    return 0;
}
