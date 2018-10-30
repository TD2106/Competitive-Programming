#include <bits/stdc++.h>
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define reset(a) memset(a,0,sizeof(a))
#define all(a) a.begin(),a.end()
#define pb push_back
#define ins insert
#define mp make_pair
#define fi first
#define se second
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long int ll;
typedef unsigned long long int llu;
typedef long double lf;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int main(){
    int n,a[101],b[101],cnta[6]={0},cntb[6]={0},Ti=0,t;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnta[a[i]]++;
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        cntb[b[i]]++;
    }
    for(int i=1;i<=5;i++){
        if((cnta[i]+cntb[i])%2){
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int i=1;i<=5;i++){
        t=cnta[i]+cntb[i];
        t/=2;
        if(cnta[i]>t) Ti+=cnta[i]-t;
        else if(cntb[i]>t) Ti+=cntb[i]-t;
    }
    cout<<Ti/2<<endl;
    return 0;
}



