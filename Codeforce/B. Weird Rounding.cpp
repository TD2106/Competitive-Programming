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
    string n;
    int k,Ti=0,cnt=0;
    cin>>n>>k;
    if(n=="0"){
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<n.size();i++){
        if(n[i]=='0') cnt++;
    }
    if(cnt<k&&cnt>=1){
        cout<<n.size()-1<<endl;
        return 0;
    }
    else{
        cnt=0;
        for(int i=n.size()-1;i>=0&&cnt<k;i--){
            if(n[i]=='0') cnt++;
            else Ti++;
        }
        cout<<Ti<<endl;
    }
    return 0;
}



