#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll n,k,Ti=0,t;
bool isPrime[100005]={0};
vector<ll> prime;
void sieve(){
    for(ll i=2;i<=1e5;i++){
        if(!isPrime[i]){
            prime.push_back(i);
            for(ll j=i*i;j<=1e5;j+=i){
               isPrime[j]=1;
            }
        }
    }
}
int main(){
    cin>>n>>k;
    t=n;
    sieve();
    //cout<<prime.size()<<endl;
    for(int i=0;i<prime.size();i++){
        if(t%prime[i]==0){
            while(t%prime[i]==0){
                Ti++;
                t/=prime[i];
                //cout<<t<<" "<<Ti<<endl;
            }
            //cout<<prime[i]<<endl;
        }
    }
    if(Ti<k) cout<<-1<<endl;
    else{
        Ti=0;
        for(int i=0;i<prime.size()&&Ti<(k-1);i++){
           // cout<<Ti<<" "<<n<<endl;
            if(n%prime[i]==0){
                while(n%prime[i]==0&&Ti<(k-1)){
                    cout<<prime[i]<<" ";
                    Ti++;
                    n/=prime[i];
                }
            }
        }
        cout<<n<<endl;
    }
    return 0;
}
