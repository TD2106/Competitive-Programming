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
    set<char> mark;
    char check='a';
    for(int i=0;i<s.size();i++){
        if(mark.count(s[i])==0){
            if(s[i]==check){
                mark.insert(s[i]);
                check++;
            }
            else{
                cout<<"NO\n";
                return 0;
            }
        }
        else continue;
    }
    cout<<"YES\n";
    return 0;
}



