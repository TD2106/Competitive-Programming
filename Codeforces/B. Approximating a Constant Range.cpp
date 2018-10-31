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
int n,a[100005],mn=1e9+5,mx=-1,Ti=0,idx;
bool flag;
map<int,int> mark;
map<int,int>::iterator itr;
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    idx=0;
    for(int i=0;i<n;i++){
        flag=1;
        for(int j=idx;j<n;j++){
            mark[a[j]]++;
            itr=mark.begin();
            mn=(itr->first);
            itr=mark.end();
            itr--;
            mx=(itr->first);
            if(mx-mn>1){
                flag=0;
                idx=j;
                Ti=max(Ti,j-i);
                mark[a[j]]--;
                if(mark[a[j]]==0) mark.erase(a[j]);
                break;
            }
        }
        if(flag){
            Ti=max(Ti,n-i);
            break;
        }
        else{
            mark[a[i]]--;
            if(mark[a[i]]==0) mark.erase(a[i]);
        }
    }
    cout<<Ti<<endl;
    return 0;
}



