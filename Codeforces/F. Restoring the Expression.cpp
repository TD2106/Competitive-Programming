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
string s,Ti1,Ti2,Ti3;
ll hashString[1000005]={0},pow33Inv[1000005]={0},MOD=1e9+7,l1,l2,rem;
ll fastExpo(ll base,ll k,ll mod){
    ll res=1;
    base%=mod;
    while(k){
        if(k%2) res*=base;
        base*=base;
        k/=2;
        res%=mod;
        base%=mod;
    }
    return res;
}
void preCalculation(){
    ll t=1;
    pow33Inv[0]=1;
    up(i,1,1000000){
        t*=10;
        t%=MOD;
        pow33Inv[i]=fastExpo(t,MOD-2,MOD);
    }
}
void check(ll length1,ll length2,ll length){
    if(length1>0&&length2>0&&length1<=length&&length2<=length){
        ll hash3=hashString[s.size()-length];
        ll hash1=((hashString[0]-hashString[length1]+MOD)%MOD*(pow33Inv[s.size()-length1])%MOD)%MOD;
        ll hash2=((hashString[length1]-hashString[length1+length2]+MOD)%MOD*(pow33Inv[s.size()-(length1+length2)])%MOD)%MOD;

//        bug(length1);
//        bug(length2);
//        bug(length);
//        bug(hash1);
//        bug(hash2);
//        bug(hash3);
        if((hash1+hash2)%MOD==hash3){
            Ti1=s.substr(0,l1);
            Ti2=s.substr(l1,l2);
            Ti3=s.substr(l1+l2,length);
            if((Ti1[0]!='0'||length1==1)&&(Ti2[0]!='0'||length2==1)&&((Ti3[0]!='0'||length==1))){
                cout<<Ti1<<'+'<<Ti2<<'='<<Ti3<<endl;
                exit(0);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>s;
    ll t=1;
    preCalculation();
    down(i,s.size()-1,0){
        hashString[i]=(s[i]-'0')*t+hashString[i+1];
        hashString[i]%=MOD;
        t*=10;
        t%=MOD;
    }
    up(i,1,s.size()){
        rem=s.size()-i;
        if(rem/2<=i){
            l1=i;
            l2=rem-l1;
            check(l1,l2,i);
            l1=i-1;
            l2=rem-l1;
            check(l1,l2,i);
            l2=i;
            l1=rem-l2;
            check(l1,l2,i);
            l2=i-1;
            l1=rem-l2;
            check(l1,l2,i);
        }
    }
    return 0;
}
