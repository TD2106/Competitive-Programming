#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int x[100005],h[100005],Ti=0,cur,n;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;i++) cin>>x[i]>>h[i];
	Ti=1;
	cur=x[0];
	x[n]=2e9+1;
	for(int i=1;i<n;i++){
        if(x[i]-h[i]>cur) Ti++,cur=x[i];
        else if(x[i]+h[i]<x[i+1]) Ti++,cur=x[i]+h[i];
        else cur=x[i];
	}
	cout<<Ti<<endl;
	return 0;
}
