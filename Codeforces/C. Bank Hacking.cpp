#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define M 300005
using namespace std;
typedef long long int ll;
int n,a[M],Ti=2e9,u,v,temp;
vector< vector<int> > adj;
map<int,int> cnt;
int main(){
    cin>>n;
    adj.resize(n+1);
    for(int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
    for(int i=1;i<=n-1;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    map<int,int>::iterator itr=cnt.end();
    itr--;
    temp = itr->first;
    if(cnt[temp]==1){
        if(cnt[temp-1]==0) Ti = temp;
        else{
            for(int i=1;i<=n;i++){
                if(a[i]==temp){
                    int s=0;
                    for(int j=0;j<adj[i].size();j++){
                        if(a[adj[i][j]]==temp-1) s++;
                    }
                    if(s==cnt[temp-1]) Ti=temp;
                    else Ti=temp+1;
                    break;
                }
            }
        }
    }
    else{
        for(int i=1;i<=n;i++){
            if(a[i]==temp){
                int s=1;
                for(int j=0;j<adj[i].size();j++)
                if(a[adj[i][j]]==temp) s++;
                //cout<<s<<endl;
                if(s==cnt[temp]) Ti=temp+1;
            }
            else{
                int s=0;
                for(int j=0;j<adj[i].size();j++)
                if(a[adj[i][j]]==temp) s++;
                //cout<<s<<endl;
                if(s==cnt[temp]) Ti=temp+1;
            }
        }
        if(Ti==2e9) Ti=temp+2;
    }
    cout<<Ti<<endl;
    return 0;
}
