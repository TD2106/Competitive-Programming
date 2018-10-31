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
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define _CRT_SECURE_NO_WARNINGS
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
vi primes, primeFactors;
bool isPrime[1500005] = {0}, used[1500005] = {0};
int n, a[100005] = {0}, Ti[100005] = {0},idx = 0;
void primeSieve(){
    for(ll i = 2; i <= 1400000; i++){
        if(!isPrime[i]){
            primes.pb((int)i);
            for(ll j = i*i; j <= 1400000; j+=i){
                isPrime[j] = 1;
            }
        }
    }
}
bool isGoodToInsert(int x){
    primeFactors.clear();
    if(!isPrime[x]){
        if(used[x]) return 0;
        else{
            used[x] = 1;
            return 1;
        }
    }
    for(int prime:primes){
        if(x < prime || prime * prime > 100000) break;
        if(x % prime == 0){
            if(used[prime]){
                return 0;
            }
            primeFactors.pb(prime);
            while(x % prime == 0) x /= prime;
        }
    }
    if(x != 1){
        if(used[x]){
            return 0;
        }
        else primeFactors.pb(x);
    }
    for(int factor:primeFactors) used[factor] = 1;
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    primeSieve();
    cin>>n;
    up(i,1,n) cin >> a[i];
    bool larger = 0;
    up(i,1,n){
        if(larger){
            while(used[primes[idx]]) idx++;
            Ti[i] = primes[idx];
            used[primes[idx]] = 1;
            continue;
        }
        if(isGoodToInsert(a[i])){
            Ti[i] = a[i];
        }
        else{
            int temp = a[i] + 1;
            while(!isGoodToInsert(temp)) temp++;
            Ti[i] = temp;
            larger = 1;
        }
    }
    up(i,1,n) cout<< Ti[i] <<' ';
    return 0;
}
