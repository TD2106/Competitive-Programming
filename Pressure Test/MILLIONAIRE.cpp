#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
ll n,Ti=100;
bool check(ll x){
    ll digit=0,zero=0;
    bool flag=1;
    while(x){
        if(x%10==0&&flag) zero++;
        if(x%10!=0) flag=0;
        digit++;
        x/=10;
    }
    if(zero>=(digit+1)/2) return 1;
    else return 0;
}
ll process(ll x){
    while(!check(x)){
        ll temp=x,last,mul=0;
        while(temp){
            if(mul==0) mul=1;
            else mul*=10;
            if(temp%10!=0){
                last=temp%10;
                break;
            }
            temp/=10;
        }
        x+=(10-last)*mul;
    }
    return x;
}
int main(){
	ios_base::sync_with_stdio(0);
	fr("MILLIONAIRE.INP");
	fw("MILLIONAIRE.OUT");
	cin>>n;
	for(int i=1;i<=n;i++){
        Ti=process(Ti);
        cout<<Ti<<endl;
        Ti*=2;
	}
	return 0;
}
