#include <iostream>
#include <map>
#include <vector>
#define bug(x) cout << #x << " = " << x << endl;
#define pb push_back
using namespace std;
map< int,vector<int> > lan;
int dsu[105],s[105],n,m,k,t,Ti=0;
bool flag = 1;
int finddsu(int u){
    if(dsu[u]==u) return u;
    else return dsu[u]=finddsu(dsu[u]);
}
void uniondsu(int u,int v){
    int a=finddsu(u);
    int b=finddsu(v);
    if(a==b||a==v||b==a) return;
    if(s[a]>=s[b]) s[a]+=s[b],dsu[b]=a,s[b]=0;
    else s[b]+=s[a],dsu[a]=b,s[a]=0;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) dsu[i]=i,s[i]=1;
    for(int i=1;i<=n;i++){
        cin>>k;
        while(k--){
            flag = 0;
            cin>>t;
            lan[t].pb(i);
        }
    }
    if(flag){
        cout<<n<<endl;
        return 0;
    }
    map< int,vector<int> >::iterator itr;
    for(itr=lan.begin();itr!=lan.end();itr++){
        for(int i=1;i<(itr->second).size();i++){
            uniondsu((itr->second)[0],(itr->second)[i]);
        }
    }
    for(int i=1;i<=n;i++) if(s[i]) Ti++;
    cout<<Ti-1<<endl;
    return 0;
}



