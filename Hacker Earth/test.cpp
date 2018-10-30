#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,a[100005],f[100005]={0},k;
int main(){
	//ios_base::sync_with_stdio(0);
	freopen("Vanya and Array.txt","r",stdin);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=i+1;j<=n;j++){
            if(a[i]<a[j]){
                if(i==4945) cout<<j<<" "<<a[i]<<" "<<a[j]<<endl;
                sum++;
            }

        }
        f[i]=sum;
	}
	//for(int i=n;i>=1;i--) cout<<i<<" "<<f[i]<<endl;
	return 0;
}
