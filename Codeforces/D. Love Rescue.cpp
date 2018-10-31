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
int dsu[30]={0},n,t1,t2;
vector< pair<char,char> > Ti;
string s1,s2;
int find(int x){
    if(x==dsu[x]) return x;
    else return dsu[x]=find(dsu[x]);
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    dsu[x]=y;
}
int main(){
    ios_base::sync_with_stdio(0);
    up(i,0,25) dsu[i]=i;
    cin>>n>>s1>>s2;
    up(i,0,n-1){
        t1=s1[i]-'a';
        t2=s2[i]-'a';
        if(find(t1)!=find(t2)){
            Ti.pb({s1[i],s2[i]});
            merge(t1,t2);
        }
    }
    cout<<Ti.size()<<endl;
    for(auto p:Ti) cout<<p.fi<<' '<<p.se<<endl;
    return 0;
}
