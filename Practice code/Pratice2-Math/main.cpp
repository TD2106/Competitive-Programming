#include <bits/stdc++.h>
#define up(i,l,r) for(ll i=l;i<=r;i++)
#define down(i,r,l) for(ll i=r;i>=l;i--)
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define reset(a) memset(a,0,sizeof(a))
#define all(a) a.begin(),a.end()
#define endl '\n'
#define bug(x) cout<< #x << " = "<< x <<endl
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define tc() int tc;cin>>tc;up(_tc,1,tc)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
bool isPrime[100005]={0};
ll C[25][25]={0};
void primeSieve(){
    memset(isPrime,1,sizeof(isPrime));
    isPrime[1]=0;
    for(ll i=2;i*i<=100000;i++){
        if(isPrime[i]){
            for(ll j=i*i;j<=100000;j+=i) isPrime[j]=0;
        }
    }
    up(i,2,10000) if(isPrime[i]) cout<<i<<endl;
}
ll fastExpo(ll base,ll exponential,ll mod){
    base%=mod;
    ll res=1;
    while(exponential){
        if(exponential%2) res*=base;
        base*=base;
        res%=mod;
        base%=mod;
        exponential/=2;
    }
    return res;
}
ll fastMultiplication(ll a,ll b,ll mod){
    ll res=0;
    while(b){
        if(b%2) res+=a;
        a*=2;
        b/=2;
        res%=mod;
        a%=mod;
    }
    return res;
}
void calculateCombination(){
    up(i,0,20){
        up(j,0,i){
            if(j==0) C[i][j]=1;
            else C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
}
int extendedGCD(int x,int y,int& a,int &b){
    int a0=1,a1=0,b0=0,b1=1;
    while(y!=0){
        a0 -= x/y*a1;
        swap(a0,a1);
        b0 -=x/y*b1;
        swap(b0,b1);
        x%=y;
        swap(x,y);
    }
    if(x<0) a0=-a0,b0=-b0,x=-x;
    a=a0,b=b0;
    return x;
}
int main(){
//    primeSieve();
//    cout<<fastExpo(2,10,1e9+7)<<endl;
//    cout<<fastMultiplication(2,100000i,1e9+7)<<endl;
//    calculateCombination();
//    cout<<C[4][2]<<endl;
//    int a,b;
//    cout<<extendedGCD(3,4,a,b)<<endl;
//    cout<<(a%4+4)%4<<endl;

}
