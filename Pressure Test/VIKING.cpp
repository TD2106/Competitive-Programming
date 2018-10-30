#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
vector< vector<string> > Ti;
map<string,int> key;
vector< vector<int> > adj;
int n,m,u,v,cnt,tc;
string s1,s2,island[105];
bool vis[105];
int main(){
	ios_base::sync_with_stdio(0);
	fr("VIKING.INP");
	fw("VIKING.OUT");
	cin>>tc;
	while(tc--){
        Ti.clear();
        key.clear();
        adj.clear();
        adj.resize(105);
        Ti.resize(105);
        for(int i=1;i<=100;i++) Ti[i].resize(105);
        cnt=0;
        cin>>n>>m;
        while(n--){
            cin>>s1>>s2;
            if(!key.count(s1)) key[s1]=++cnt,island[cnt]=s1;
            if(!key.count(s2)) key[s2]=++cnt,island[cnt]=s2;
            u=key[s1];
            v=key[s2];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<=cnt;i++) Ti[i][i]=island[i][0];
        for(int i=1;i<=cnt;i++){
            reset(vis);
            string temp="";
            queue<int> q;
            q.push(i);
            vis[i]=1;
            while(!q.empty()){
                u=q.front();
                q.pop();
                temp=Ti[i][u];
                for(int j=0;j<adj[u].size();j++){
                    if(!vis[adj[u][j]]){
                        vis[adj[u][j]]=1;
                        q.push(adj[u][j]);
                        Ti[i][adj[u][j]]=temp+island[adj[u][j]][0];
                    }
                }
            }
        }
        //cout<<123<<endl;
        while(m--){
            cin>>s1>>s2;
            u=key[s1];
            v=key[s2];
            cout<<Ti[u][v]<<endl;
        }
	}
	return 0;
}
