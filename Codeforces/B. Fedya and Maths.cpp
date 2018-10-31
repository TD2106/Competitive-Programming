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
    string s,t;
    int Ti=0,m;
    cin>>s;
    if(s=="0") cout<<4<<endl;
    else{
        if(s.size()==1) t=s;
        else t=s[s.size()-2],t+=s[s.size()-1];
        stringstream ss;
        ss<<t;
        ss>>m;
        if(m%4==1) Ti=1+2+3+4;
        else if(m%4==2) Ti+=1+4+9+6;
        else if(m%4==3) Ti+=1+8+7+4;
        else Ti+=1+1+6+6;
        cout<<Ti%5<<endl;
    }
    return 0;
}



