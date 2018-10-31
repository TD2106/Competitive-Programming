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
set<pii> used;
int n,m,Ti1,Ti2,needPrime;
bool isPrime(int p){
    if(p==0||p==1) return 0;
    for(int i=2;i*i<=p;i++){
        if(p%i==0) return 0;
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    srand(time(NULL));
    cin>>n>>m;
    needPrime=2*(n-1);
    while(!isPrime(needPrime)) needPrime++;
    cout<<2<<' '<<needPrime<<endl;
    cout<<1<<' '<<n<<' '<<2<<endl;
    used.insert({1,n});
    used.insert({n,1});
    up(i,2,n-2){
        cout<<1<<' '<<i<<' '<<2<<endl;
        used.insert({1,i});
        used.insert({i,1});
    }
    if(n-1!=1){
        cout<<1<<' '<<n-1<<' '<<needPrime-2*(n-2)<<endl;
        used.insert({1,n-1});
        used.insert({n-1,1});
    }
    m-=(n-1);
    while(m){
        Ti1=rand()%n+1;
        Ti2=rand()%n+1;
        if(Ti1!=Ti2&&used.count({Ti1,Ti2})==0){
            cout<<Ti1<<' '<<Ti2<<' '<<needPrime-2*(n-2)+1<<endl;
            used.insert({Ti1,Ti2});
            used.insert({Ti2,Ti1});
            m--;
        }
    }
    return 0;
}
