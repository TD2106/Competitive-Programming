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
ll tc,n,mod=111539786,mtrxFibo[2][2],res[2][2];
void mulMatrix(ll mtrx1[][2],ll mtrx2[][2]){
    ll result[2][2]={0};
    up(i,0,1){
        up(j,0,1){
            up(k,0,1){
                result[i][j]+=mtrx1[i][k]*mtrx2[k][j]%mod;
                result[i][j]%=mod;
            }
        }
    }
    up(i,0,1) up(j,0,1) mtrx1[i][j]=result[i][j];
}
void fastPowMatrix(ll k,ll mtrx[][2]){
    res[0][0]=1,res[0][1]=0,res[1][0]=0,res[1][1]=1;
    while(k){
        if(k%2) mulMatrix(res,mtrx);
        mulMatrix(mtrx,mtrx);
        k/=2;
    }
}
ll fibonacci(ll nth){
    nth-=2;
    mtrxFibo[0][0]=0,mtrxFibo[0][1]=mtrxFibo[1][0]=mtrxFibo[1][1]=1;
    fastPowMatrix(nth,mtrxFibo);
    return (res[1][0]*1+res[1][1]*2)%mod;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>tc;
    while(tc--){
        cin>>n;
        if(n==1) cout<<1<<endl;
        else if(n==2) cout<<2<<endl;
        else cout<<fibonacci(n)<<endl;
    }
    return 0;
}
