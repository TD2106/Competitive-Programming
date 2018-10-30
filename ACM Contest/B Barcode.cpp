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
ll tc,n,m,dp[1000005],cnt=0,p1,p2,temp,Ti;
ll fastExpo(ll base,ll k,ll mod){
    ll res=1;
    while(k){
        if(k%2) res*=base;
        base*=base;
        k/=2;
        res%=mod;
        base%=mod;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>tc;
    while(tc--){
        cin>>n>>m;
        dp[0]=1;
        dp[1]=2%m;
        up(i,2,n) dp[i]=(dp[i-1]+dp[i-2])%m;
        if(n%2) Ti=dp[n];
        else{
            temp=n/2+1;
            temp%=m;
            Ti=(dp[n]-temp+m)%m;
            p1=p2=1;
            up(i,1,n/2){
                temp=i;
                while(temp%m==0){
                    temp/=m;
                    cnt+=2;
                }
                p1*=temp;
                p1%=m;
            }
            p1*=p1;
            p1%=m;
            up(i,1,n){
                temp=i;
                while(temp%m==0&&cnt>0){
                    temp/=m;
                    cnt--;
                }
                p2*=temp;
                p2%=m;
            }
            Ti=(Ti+(p2*fastExpo(p1,m-2,m))%m)%m;
        }
        cout<<Ti<<endl;
    }
    return 0;
}
