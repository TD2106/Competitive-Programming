#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
#define up(i,l,r) for(int i=l;i<=r;i++)
#define down(i,r,l) for(int i=r;i>=l;i--)
#define mod 1000000007
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
int n,k,Ti=-1,l,r;
string s[30005];
set<string> st[30005];
map<string,int> cnt;
set<string>::iterator itr;
int main(){
    ios_base::sync_with_stdio(0);
//    fr("GENE.INP");
//    fw("GENE.OUT");
    cin>>n>>k;
    l=1,r=30;
    if(k==1){
        cout<<30<<endl;
        return 0;
    }
    up(i,1,n) cin>>s[i];
    while(l<=r){
        int i=(l+r)/2;
        bool flag=0;
        cnt.clear();
        up(j,1,n){
            st[j].clear();
            up(l,0,30-i) st[j].insert(s[j].substr(l,i));
            for(itr=st[j].begin();itr!=st[j].end();itr++){
                cnt[*itr]++;
                if(cnt[*itr]>=k){
                    Ti=max(Ti,i);
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) l=i+1;
        else r=i-1;
    }
    cout<<Ti<<endl;
    return 0;
}
