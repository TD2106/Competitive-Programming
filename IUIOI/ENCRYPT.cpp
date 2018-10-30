#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define reset(x) memset(x,0,sizeof(x))
#define MOD 1000000007
using namespace std;
typedef long long int ll;
ll dpl[100005],dpr[100005],k,idx,H,revH,pow33[100005];
ll fastPow(ll base,ll k){
    ll res=1;
    while(k){
        if(k%2) res*=base;
        base*=base;
        k/=2;
        base%=MOD;
        res%=MOD;
    }
    return res;
}
void precompute(){
    ll res=1;
    pow33[0]=1;
    for(int i=1;i<=100000;i++){
        res*=33;
        res%=MOD;
        pow33[i]=fastPow(res,MOD-2);
    }
}
int main(){
	ios_base::sync_with_stdio(0);
	fr("ENCRYPT.INP");
	fw("ENCRYPT.OUT");
	string Ti,temp;
	precompute();
	while(cin>>Ti){
        dpl[0]=0;
        dpr[Ti.size()+1]=0;
        temp.clear();
        k=1;
        for(int i=1;i<=Ti.size();i++){
            dpl[i]=(dpl[i-1]+(Ti[i-1])*k)%MOD;
            k*=33;
            k%=MOD;
        }
        k=1;
        for(int i=Ti.size();i>=1;i--){
            dpr[i]=(dpr[i+1]+(Ti[i-1])*k)%MOD;
            k*=33;
            k%=MOD;
        }
        for(int i=1;i<=Ti.size();i++){
            H=(dpl[Ti.size()]-dpl[i-1]+MOD)%MOD;
            H=(H*pow33[i-1])%MOD;
            revH=dpr[i];
            if(H==revH) break;
            else temp.push_back(Ti[i-1]);
        }
        reverse(temp.begin(),temp.end());
        cout<<Ti+temp<<endl;
	}
	return 0;
}
