#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
ll n,k,Ti[100005]={0},a[100005];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
        cin>>a[i];
        Ti[i]=Ti[i-1]+i;
	}
	for(int i=1;i<=n;i++){
        if(Ti[i]>=k){
            cout<<a[k-Ti[i-1]]<<endl;
            break;
        }
	}
	return 0;
}
