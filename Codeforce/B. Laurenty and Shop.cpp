#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int Ti=0,temp,n,a1[55]={0},a2[55]={0},avenue[55]={0},used;
int cross1(int idx){
    int res=0;
    res+=avenue[idx];
    for(int i=n-1;i>=idx;i--) res+=a2[i];
    for(int i=idx-1;i>=1;i--) res+=a1[i];
    return res;
}
int cross2(int idx){
    int res=0;
    res+=avenue[idx];
    for(int i=1;i<=idx-1;i++) res+=a1[i];
    for(int i=idx;i<=n-1;i++) res+=a2[i];
    return res;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n-1;i++) cin>>a1[i];
	for(int i=1;i<=n-1;i++) cin>>a2[i];
	for(int i=1;i<=n;i++) cin>>avenue[i];
	temp=1e9;
	for(int i=1;i<=n;i++){
         if(cross1(i)<temp){
            used=i;
            temp=cross1(i);
         }
	}
	Ti+=temp,temp=1e9;
	for(int i=1;i<=n;i++){
        if(i!=used)  temp=min(temp,cross2(i));
	}
	Ti+=temp;
	cout<<Ti<<endl;
	return 0;
}
