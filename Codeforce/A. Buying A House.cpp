#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,m,Ti=1e9,k,a[101]={0};
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=m-1;i>0;i--){
        if(a[i]!=0&&a[i]<=k) Ti=min(Ti,(m-i)*10);
    }
    for(int i=m+1;i<=n;i++){
        if(a[i]!=0&&a[i]<=k) Ti=min(Ti,(i-m)*10);
    }
    cout<<Ti<<endl;
    return 0;
}
