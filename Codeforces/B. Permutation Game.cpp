#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,m,Ti[105]={0},l[105],t;
bool vis[105]={0};
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>l[i];
	for(int i=1;i<=m-1;i++){
        t=l[i+1]-l[i];
        if(t<=0) t+=n;
        if(Ti[l[i]]==0&&vis[t]==0) Ti[l[i]]=t,vis[t]=1;
        else if(Ti[l[i]]==t) continue;
        else{
            cout<<-1<<endl;
            return 0;
        }
	}
	for(int i=1;i<=n;i++){
        if(Ti[i]==0){
            for(int j=1;j<=n;j++){
                if(!vis[j]){
                    vis[j]=1;
                    Ti[i]=j;
                    break;
                }
            }
        }
	}
	for(int i=1;i<=n;i++) cout<<Ti[i]<<" ";
	return 0;
}
