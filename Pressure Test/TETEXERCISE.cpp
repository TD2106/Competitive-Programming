#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int n,k,sum[100005]={0},a[100005],mark[100005]={0},idx,t;
bool dp[1005][100005]={0};
vector<int> Ti;
int main(){
	ios_base::sync_with_stdio(0);
	fr("TETEXERCISE.INP");
	fw("TETEXERCISE.OUT");
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k<n){
        for(int i=1;i<=n;i++) sum[i]=(sum[i-1]+a[i])%k;
        for(int i=1;i<=n;i++){
            if(mark[sum[i]]!=0){
                for(int j=mark[sum[i]]+1;j<=i;j++){
                    Ti.push_back(j);
                }
                break;
            }
            else mark[sum[i]]=i;
        }
	}
	else{
        dp[1][a[1]%k]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<k;j++){
                dp[i][j]=dp[i-1][j]|dp[i-1][(j-a[i]+k)%k];
            }
            dp[i][a[i]%k]=1;
            if(dp[i][0]){
                idx=i;
                t=0;
                while(a[idx]%k!=t){
                    if(dp[idx][t]==1&&dp[idx-1][t]==0){
                        Ti.push_back(idx);
                        t=(t-a[idx]+k)%k;
                    }
                    idx--;
                }
                Ti.push_back(idx);
                reverse(Ti.begin(),Ti.end());
                break;
            }
        }
	}
	if(Ti.size()==0) cout<<"NO\n";
	else{
        cout<<"YES\n";
        cout<<Ti.size()<<endl;
        for(int i=0;i<Ti.size();i++) cout<<Ti[i]<<" ";
	}
	return 0;
}
