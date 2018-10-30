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
int trie[600005][3]={0},n,m,node=0;
bool Ti=0,ended[600005]={0};
string s;
void insert(const string &str){
    int v=0,tmp;
    up(i,0,str.size()-1){
        tmp=s[i]-'a';
        if(trie[v][tmp]==0) trie[v][tmp]=++node;
        v=trie[v][tmp];
    }
    ended[v]=1;
}
void go(int idx,int v,bool taken){
    if(Ti) return;
    if(idx==s.size()&&ended[v]&&taken) Ti=1;
    if(idx==s.size()) return;
    int tmp=s[idx]-'a';
    if(trie[v][tmp]==0&&taken==1) return;
    if(taken) go(idx+1,trie[v][tmp],taken);
    else{
        if(trie[v][tmp]) go(idx+1,trie[v][tmp],taken);
        up(i,1,2){
            if(trie[v][(tmp+i)%3]) go(idx+1,trie[v][(tmp+i)%3],1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    up(i,1,n){
        cin>>s;
        insert(s);
    }
    up(i,1,m){
        cin>>s;
        Ti=0;
        go(0,0,0);
        if(Ti) cout<<"YES";
        else cout<<"NO";
        cout<<'\n';
    }
    return 0;
}
