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
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
map<pii,int> pay;
int n,a,b,f,k,Ti=0,idx=0,pre=0,cur;
map<string,int> key;
multiset<int> ms;
string s1,s2;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>a>>b>>k>>f;
    up(i,1,n){
        cin>>s1>>s2;
        if(!key.count(s1)) key[s1]=++idx;
        if(!key.count(s2)) key[s2]=++idx;
        int temp;
        if(key[s1]==pre) Ti+=b,temp=b;
        else Ti+=a,temp=a;
        pre=key[s2];
        if(pay.count({key[s1],key[s2]})) pay[{key[s1],key[s2]}]+=temp;
        else if (pay.count({key[s2],key[s1]})) pay[{key[s2],key[s1]}]+=temp;
        else pay[{key[s1],key[s2]}]+=temp;
    }
    cur=Ti;
    for(auto itr:pay) ms.insert(itr.se);
    up(i,1,k){
        if(ms.empty()) break;
        int temp = *(--ms.end());
        cur=cur-temp+f;
        Ti=min(Ti,cur);
        ms.erase(--ms.end());
    }
    cout<<Ti<<endl;
    return 0;
}
