#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll a[100005]={0},Ti=0,c[2][100005]={0},tmp,n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    tmp=1;
    for(int i=1;i<=n-1;i++) c[0][i]=abs(a[i+1]-a[i])*tmp,tmp*=-1;
    tmp=1;
    for(int i=2;i<=n-1;i++) c[1][i]=abs(a[i+1]-a[i])*tmp,tmp*=-1;
    for(int i=0;i<2;i++){
        tmp=0;
        for(int j=1;j<=n-1;j++){
            tmp+=c[i][j];
            if(tmp>=0) Ti=max(Ti,tmp);
            else tmp=0;
        }
    }
    cout<<Ti<<endl;
    return 0;
}
