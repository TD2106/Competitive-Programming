#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll n,h,k,a[100005],Ti=0,cur=0,idx=0;
int main(){
	ios_base::sync_with_stdio(0);
    cin>>n>>h>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    while(idx!=n){
        while(cur+a[idx]<=h&&idx!=n) cur+=a[idx],idx++;
        if(cur>k) Ti+=cur/k;
        else Ti++;
        if(cur>k) cur%=k;
        else cur=0;
        //cout<<cur<<" "<<Ti<<" "<<idx<<endl;
    }
    Ti+=cur/k+bool(cur%k);
    cout<<Ti<<endl;
	return 0;
}
