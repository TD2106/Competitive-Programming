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
    string s;
    cin>>s;
    bool Ti=0;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]=='A'&&s[i+1]=='B'){
            for(int j=i+2;j<s.size()-1;j++){
                if(s[j]=='B'&&s[j+1]=='A') Ti=1;
            }
            break;
        }
    }
    for(int i=0;i<s.size()-1;i++){
        if(s[i]=='B'&&s[i+1]=='A'){
            for(int j=i+2;j<s.size()-1;j++){
                if(s[j]=='A'&&s[j+1]=='B') Ti=1;
            }
            break;
        }
    }
    if(Ti) cout<<"YES";
    else cout<<"NO";
    return 0;
}



