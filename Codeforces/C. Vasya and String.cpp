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
int n,k,Ti=0,idx,a,b,t;
bool flag;
string s;
int main(){
    cin>>n>>k>>s;
    idx=a=b=0;
    for(int i=0;i<n;i++){
        flag=1;
        for(int j=idx;j<n;j++){
            if(s[j]=='a') a++;
            else b++;
            t=min(a,b);
            if(t>k){
                flag=0;
                Ti=max(Ti,b+a-1);
                idx=j;
                if(s[j]=='a') a--;
                else b--;
                break;
            }
        }
        if(flag){
            Ti=max(Ti,b+a);
            break;
        }
        else{
            if(s[i]=='a') a--;
            else b--;
        }
    }
    cout<<Ti<<endl;
    return 0;
}



