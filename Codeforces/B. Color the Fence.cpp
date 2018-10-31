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
string Ti;
int v,a[10]={0},l,mn=1e9,mark;
char temp;
string compare(string s1,string s2){
    if(s1.size()>s2.size()) return s1;
    else if(s1.size()==s2.size()&&s1>s2) return s1;
    else return s2;
}
int main(){
    cin>>v;
    for(int i=1;i<=9;i++){
        cin>>a[i];
        if(a[i]<=mn){
            mn=a[i];
            mark=i;
        }
    }
    temp='0'+mark;
    for(int i=0;i<(v/mn);i++){
        Ti+=temp;
    }
    v%=mn;
    for(int i=0;i<Ti.size()&&v>0;i++){
        for(int j=9;j>mark;j--){
            if(v>=(a[j]-mn)){
                v-=(a[j]-mn);
                Ti[i]=('0'+j);
                break;
            }
        }
    }
    if(Ti.size()==0) cout<<-1<<endl;
    else cout<<Ti<<endl;
}



