#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll n,m,x[100005],y[100005],mod = 1e9+7, xsum=0,ysum=0,Ti=0,t;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1;i<=m;i++) cin>>y[i];
    sort(x+1,x+n+1);
    sort(y+1,y+m+1);
    t=1;
    for(int i=m;i>1;i--){
        ysum+=(y[i]-y[i-1])*(i-1)*t;
        t++;
        ysum%=mod;
    }
    t=1;
    for(int i=n;i>1;i--){
        xsum+=(x[i]-x[i-1])*(i-1)*t;
        t++;
        xsum%=mod;
    }
    Ti=xsum*ysum;
    Ti%=mod;
    cout<<Ti<<endl;
    return 0;
}
