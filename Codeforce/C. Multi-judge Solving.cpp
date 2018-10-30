#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,k,Ti=0,a[1005];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
        if(k>=(a[i]+1)/2) k=max(k,a[i]);
        else{
            while(k<(a[i]+1)/2){
                Ti++;
                k*=2;
            }
            k=a[i];
        }
	}
	cout<<Ti<<endl;
	return 0;
}
