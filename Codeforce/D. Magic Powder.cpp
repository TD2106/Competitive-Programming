#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
ll n,k,l=0,r=2e9,Ti=0,a[100005],b[100005],temp;
bool check(int x){
    temp=k;
    //bug(x);
    for(int i=1;i<=n;i++){
        if(x*a[i]>b[i]) temp-=(x*a[i]-b[i]);
        if(temp<0) return 0;
    }
    return 1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	while(l<=r){
//        cout<<l<<" "<<r<<endl;
        ll mid=(l+r)/2;
        if(check(mid)){
            Ti=max(Ti,mid);
            l=mid+1;
        }
        else r=mid-1;
	}
	cout<<Ti<<endl;
	return 0;
}
