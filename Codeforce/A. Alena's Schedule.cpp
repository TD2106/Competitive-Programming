#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int Ti=0,first=1e7,last=0,a[105]={0},c0=0,n;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]){
            first=min(first,i);
            last=max(last,i);
        }
	}
	for(int i=first;i<=last;i++){
        if(a[i]){
            if(c0<=1) Ti+=c0;
            c0=0;
            Ti++;
        }
        else c0++;
	}
	cout<<Ti<<endl;
	return 0;
}
