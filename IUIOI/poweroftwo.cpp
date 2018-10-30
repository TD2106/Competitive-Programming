#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
vector<ll> prime;
bool isPrime[1005]={0};
ll Ti[1000005]={0},tc,n;
void sieve(){
    for(ll i=2;i<=1e3;i++){
        if(!isPrime[i]){
            for(ll j=i*i;j<=1e3;j+=i) isPrime[j]=1;
            prime.push_back(i);
        }
    }
}
ll divisor(ll x){
    ll re=1,t=0,p=0,o=x;
    for(int i=0;i<prime.size()&&x>=prime[i];i++){
       // cout<<prime[i]<<endl;
        if(x%prime[i]==0){
            p=prime[i];
            while(x%prime[i]==0){
                t++;
                x/=prime[i];
            }
            break;
        }
    }
    if(p==0) re*=2;
    else re=(Ti[o/p]+1)/(t)*(t+1);
    return re-1;
}
int main(){
    sieve();
    for(ll i=2;i<=1e6;i++){
        Ti[i]=divisor(i);
        //cout<<i<<" "<<Ti[i]<<endl;
    }
    for(ll i=2;i<=1e6;i++) Ti[i]+=Ti[i-1];
    cin>>tc;
    while(tc--){
        cin>>n;
        cout<<Ti[n]<<endl;
    }
	return 0;
}
