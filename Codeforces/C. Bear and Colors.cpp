#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
int Ti[5005]={0},n,t[5005],sum[5005],mx,cur;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>t[i];
	for(int i=1;i<=n;i++){
        reset(sum);
        mx=cur=0;
        for(int j=i;j<=n;j++){
            sum[t[j]]++;
            if(mx<sum[t[j]]){
                mx=sum[t[j]];
                cur=t[j];
            }
            else if(mx==sum[t[j]]) cur=min(cur,t[j]);
            Ti[cur]++;
           // cout<<i<<" "<<j<<" "<<cur<<endl;
        }
	}
	for(int i=1;i<=n;i++) cout<<Ti[i]<<" ";
	return 0;
}
