#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,a,pos[100005],c=0,Ti=1e9;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>a;
	if(n==1){
        cout<<0<<endl;
        return 0;
	}
	for(int i=1;i<=n;i++) cin>>pos[i];
	sort(pos+1,pos+1+n);
	Ti=min(abs(a-pos[1])+pos[n-1]-pos[1],abs(a-pos[n-1])+pos[n-1]-pos[1]);
    Ti=min(Ti,min(abs(a-pos[2])+pos[n]-pos[2],abs(a-pos[n])+pos[n]-pos[2]));
	cout<<Ti<<endl;
	return 0;
}
