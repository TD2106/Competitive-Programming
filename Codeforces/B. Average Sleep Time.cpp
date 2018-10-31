#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define M 200005
using namespace std;
typedef long long int ll;

int main(){
    int n,k;
    double a[M]={0},Ti=0,t;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>t;
        a[i]=a[i-1]+t;
    }
    for(int i=1;i<=n-k+1;i++) Ti+=a[i+k-1]-a[i-1];
    Ti/=(n-k+1);
    cout<<fixed<<setprecision(6)<<Ti<<endl;
	return 0;
}
