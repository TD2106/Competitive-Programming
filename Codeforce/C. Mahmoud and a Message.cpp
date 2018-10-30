#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
#define up(i,l,r) for(int i=l;i<=r;i++)
#define down(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
typedef long long int ll;
string s;
ll dp[1005]={0},a[30]={0},Timax=0,mod=1e9+7,dpNum[1005],n;
bool check(string x){
    for(auto c:x) if(x.size()>a[c-'a']) return 0;
    return 1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>s;
	up(i,0,25) cin>>a[i];
	dp[0]=1;
	dpNum[0]=0;
	up(i,1,n){
	    dpNum[i]=1e9;
        down(j,i,1){
            if(!check(s.substr(j-1,i-j+1))) break;
            else{
                Timax=max(Timax,(ll)(i-j+1)),dpNum[i]=min(dpNum[i],1+dpNum[j-1]);
                dp[i]+=dp[j-1];
                dp[i]%=mod;
            }
        }
	}
	cout<<dp[n]<<endl<<Timax<<endl<<dpNum[n]<<endl;
	return 0;
}
