#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int degree[101]={0},n,m,u,v,Ti=0,flag=1;
vector< vector<int> > adj;
int main(){
    cin>>n>>m;
    adj.resize(n+1);
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++) degree[i]=adj[i].size();
    while(flag){
        flag=0;
        vector<int> temp;
        for(int i=1;i<=n;i++){
            if(degree[i]==1){
                flag=1;
                temp.push_back(i);
            }
        }
        if(flag){
            Ti++;
            for(int i=0;i<temp.size();i++){
                degree[temp[i]]=0;
                for(int j=0;j<adj[temp[i]].size();j++){
                    if(degree[adj[temp[i]][j]]>0) degree[adj[temp[i]][j]]--;
                }
            }
        }
    }
    cout<<Ti<<endl;
	return 0;
}
