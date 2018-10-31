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
ll strtoll(string s){
    ll ans;
    stringstream ss;
    ss<<s;
    ss>>ans;
    return ans;
}
ll Ti=0;
int main(){
    ios_base::sync_with_stdio(false);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++) if((s[i]-'0')%4==0) Ti++;
    for(int i=0;i<s.size()-1;i++){
        string temp;
        temp+=s[i];
        temp+=s[i+1];
        if(strtoll(temp)%4==0) Ti+=i+1;
    }
    cout<<Ti<<endl;
    return 0;
}



