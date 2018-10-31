#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll f[5000005]={0},Ti=0,l,r,t,p=1,mod=1e9+7;
void sieveAndCompute(){
    for(ll i=2;i<=5*1e6;i++) f[i]=i;
    for(ll i=2;i<=5*1e6;i++){
        if(f[i]==i){
            for(ll j=i*i;j<=5*1e6;j+=i) f[j]=min(f[j],i);
        }
    }
    for(ll i=2;i<=5*1e6;i++){
        if(f[i]==i){
            f[i]=(i*(i-1)/2)%mod;
            for(ll j=i*i;j<=5*1e6;j+=i){

            }
        }
    }
    //for(ll i=2;i<=5*1e6;i++) f[i]%=mod;
}
int main(){
	ios_base::sync_with_stdio(0);
	sieveAndCompute();
	cin>>t>>l>>r;
	for(int i=l;i<=r;i++){
        //cout<<f[i]<<" ";
        Ti=(Ti+p*f[i])%mod;
        p*=t;
        p%=mod;
        Ti%=mod;
	}
	cout<<Ti<<endl;
	return 0;
}
