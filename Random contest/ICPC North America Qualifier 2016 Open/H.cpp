#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
int dp1[100005]={0},dp2[100005]={0},temp[100005]={0},n,m,bun[105],hd[105],Ti=2e5;
bool isGood[100005];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>bun[i];
	cin>>m;
	for(int i=1;i<=m;i++) cin>>hd[i];
	for(int i=1;i<=1e5;i++) dp1[i]=dp2[i]=1e5;
    reset(isGood);
    isGood[0]=1;
	for(int i=1;i<=n;i++){
        reset(temp);
        for(int j=1;j<=1e5;j++){
            if(j>=bun[i]&&isGood[j-bun[i]]){
                temp[j]=dp1[j-bun[i]]+1;
                isGood[j]=1;
            }
        }
        for(int j=1;j<=1e5;j++){
            if(temp[j]) dp1[j]=min(temp[j],dp1[j]);
        }
	}
	//cout<<dp1[10]<<endl;
    reset(isGood);
    isGood[0]=1;
	for(int i=1;i<=m;i++){
        reset(temp);
        for(int j=1;j<=1e5;j++){
            if(j>=hd[i]&&isGood[j-hd[i]]){
                temp[j]=dp2[j-hd[i]]+1;
                isGood[j]=1;
            }
        }
        for(int j=1;j<=1e5;j++){
            if(temp[j]) dp2[j]=min(temp[j],dp2[j]);
        }
	}
	for(int i=1;i<=1e5;i++){
        if(dp1[i]&&dp2[i]) Ti=min(Ti,dp1[i]+dp2[i]);
	}
	if(Ti<=n+m) cout<<Ti<<endl;
	else cout<<"impossible\n";
	return 0;
}
