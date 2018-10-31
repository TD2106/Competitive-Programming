#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,m,out[100005]={0},u,v,idx[100005],ptr,Ti[100005];
vector< vector<int> > parent;
priority_queue<int> pq;
bool cmp(int a,int b){
    return out[a]<out[b];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	ptr=n;
	parent.resize(n+1);
	while(m--){
        cin>>u>>v;
        out[u]++;
        parent[v].push_back(u);
	}
	for(int i=1;i<=n;i++) idx[i]=i;
	sort(idx+1,idx+1+n,cmp);
	for(int i=1;i<=n&&out[idx[i]]==0;i++) pq.push(idx[i]);
	vector<int> temp;
	while(ptr!=0){
        while(!pq.empty()){
            Ti[pq.top()]=ptr--;
            for(int i=0;i<parent[pq.top()].size();i++){
                out[parent[pq.top()][i]]--;
                if(out[parent[pq.top()][i]]==0) temp.push_back(parent[pq.top()][i]);
            }
            pq.pop();
            for(int i=0;i<temp.size();i++) pq.push(temp[i]);
            temp.clear();
        }
	}
	for(int i=1;i<=n;i++) cout<<Ti[i]<<" ";
	return 0;
}
