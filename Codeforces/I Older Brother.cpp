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
vi primes;
bool isPrime[100005] = {0}, Ti = 1;
int q;
void primeSieve(){
    up(i, 2, 100000){
        if(!isPrime[i]){
            primes.pb(i);
            for(ll j = (ll)i * (ll)i; j <= 100000; j+=i){
                isPrime[j] = 1;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    primeSieve();
    cin >> q;
    if(q == 1){
        cout << "no";
        return 0;
    }
    for(int p : primes){
        if(q % p == 0){
            while(q % p == 0) q /= p;
            if(q != 1){
                Ti = 0;
            }
            break;
        }
    }
    if(Ti) cout <<"yes";
    else cout <<"no";
    return 0;
}
