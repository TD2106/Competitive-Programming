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
int trie[19*1000000+5][10]={0},n,node=0;
string s,Timx="",Timn="";
void add(){
    int v=0,tmp;
    up(i,0,s.size()-1){
        tmp=s[i]-'0';
        if(trie[v][tmp]==0) trie[v][tmp]=++node;
        v=trie[v][tmp];
    }
}
string queryMin(){
    string res="";
    int v=0,tmp,nxt,mn;
    up(i,0,s.size()-1){
        mn=10;
        tmp=s[i]-'0';
        up(j,0,9){
            if(trie[v][j]!=0&&((tmp+j)%10)<mn){
                nxt=trie[v][j],mn=(tmp+j)%10;
            }
        }
        res+=('0'+mn);
        v=nxt;
    }
    return res;
}
string queryMax(){
    string res="";
    int v=0,tmp,nxt,mx;
    up(i,0,s.size()-1){
        tmp=s[i]-'0';
        mx=-1;
        up(j,0,9){
            if(trie[v][j]!=0&&((tmp+j)%10)>mx) nxt=trie[v][j],mx=(tmp+j)%10;
        }
        res+=('0'+mx);
        v=nxt;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n){
        cin>>s;
        reverse(all(s));
        while(s.size()<=19) s.pb('0');
        reverse(all(s));
        if(i!=1){
            if(i==2){
                Timx=queryMax();
                Timn=queryMin();
            }
            else{
                Timx=max(Timx,queryMax());
                Timn=min(Timn,queryMin());
            }
        }
        add();
    }
    reverse(all(Timx));
    while(Timx.size()!=1&&Timx[Timx.size()-1]=='0') Timx.pop_back();
    reverse(all(Timn));
    while(Timn.size()!=1&&Timn[Timn.size()-1]=='0') Timn.pop_back();
    reverse(all(Timx));
    reverse(all(Timn));
    cout<<Timn<<' '<<Timx<<endl;
    return 0;
}
