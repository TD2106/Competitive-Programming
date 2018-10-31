#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,k,Ti=0,s[100005],idx=1;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>s[i];
	while(2*k>n&&n>0) Ti=max(Ti,s[n--]),k--;
	for(int i=n;i>idx;i--,idx++){
        if(idx==i) Ti=max(Ti,s[i]);
        else Ti=max(Ti,s[i]+s[idx]);
	}
	cout<<Ti<<endl;
	return 0;
}
