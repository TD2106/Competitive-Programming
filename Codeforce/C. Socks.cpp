#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define M 200005
using namespace std;
typedef long long int ll;
int n,m,k,c[M],Ti=0,l,r,d[M],s[M]={0},mx;
vector<int> v[M];
map<int,int> cnt;
int fn(int x){
    if(x==d[x]) return x;
    else return d[x]=fn(d[x]);
}
void un(int x,int y){
    x=fn(x);
    y=fn(y);
    if(x==y) return ;
    if(s[x]<s[y]) swap(x,y);
    d[y]=x;
    s[x]+=s[y];
    s[y]=0;
}
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>c[i],d[i]=i,s[i]=1;
    for(int i=1;i<=m;i++){
        cin>>l>>r;
        un(l,r);
    }
    for(int i=1;i<=n;i++) v[fn(i)].push_back(i);
    for(int i=1;i<=n;i++){
        if(s[i]>1){
            mx=0;
            cnt.clear();
            for(int j=0;j<v[i].size();j++){
                cnt[c[v[i][j]]]++;
                if(cnt[c[v[i][j]]]>mx) mx=cnt[c[v[i][j]]];
            }
            Ti+=s[i]-mx;
        }
    }
    cout<<Ti<<endl;
    return 0;
}
