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
    int n,m=0,po[1001];
    string s[1001],Ti;
    map<string,int> pl,te;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i]>>po[i];
        pl[s[i]]+=po[i];
    }
    for(int i=0;i<n;i++) m=max(pl[s[i]],m);
    for(int i=0;i<n;i++){
        if(pl[s[i]]==m&&(te[s[i]]+=po[i])>=m){
            Ti=s[i];
            cout<<Ti<<endl;
            break;
        }
    }
    return 0;
}



