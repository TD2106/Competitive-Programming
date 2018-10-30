#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int n,a,b,Ti=0,x[105],y[105];
void check(int x0,int x1,int y0,int y1){
    if((x0+x1)<=a&&(y0<=b)&&(y1<=b)){
        Ti=max(Ti,x0*y0+x1*y1);
    }
    if((y0+y1)<=b&&(x0<=a)&&(x1<=a)){
        Ti=max(Ti,x0*y0+x1*y1);
    }
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>a>>b;
	for(int i=0;i<n;i++) cin>>x[i]>>y[i];
	for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            check(x[i],x[j],y[i],y[j]);
            check(y[i],x[j],x[i],y[j]);
            check(x[i],y[j],y[i],x[j]);
            check(y[i],y[j],x[i],x[j]);
        }
	}
	cout<<Ti<<endl;
	return 0;
}
