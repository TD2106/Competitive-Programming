#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int r[100005]={0},u,v,n,m,Ti=0,idx1,idx2;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	//cout<<n<<m<<endl;
	for(int i=1;i<=m;i++){
        cin>>u>>v;
        if(u<v) swap(u,v);
        if(r[u]==1||r[v]==2){
            cout<<Ti<<endl;
            return 0;
        }
        r[u]=2;
        r[v]=1;
	}
	if(r[1]==2||r[n]==1){
        cout<<Ti<<endl;
        return 0;
	}
	r[1]=1,r[n]=2,Ti=1;
	for(int i=n;i>=1;i--) if(r[i]==1) {idx1=i;break;}
	for(int i=1;i<=n;i++) if(r[i]==2) {idx2=i;break;}
	if(idx1<idx2) Ti+=idx2-idx1-1;
	else Ti=0;
	cout<<Ti<<endl;
	return 0;
}
