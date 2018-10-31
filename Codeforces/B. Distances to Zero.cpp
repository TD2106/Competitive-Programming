#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define M 200005
using namespace std;
typedef long long int ll;
int n,a[M],Ti[M];
int main(){
    cin>>n;
    Ti[0]=Ti[n+1]=1e9;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        Ti[i]=1e9;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==0) Ti[i]=0;
        Ti[i]=min(Ti[i-1]+1,Ti[i]);
    }
    for(int i=n;i>=1;i--){
        if(a[i]==0) Ti[i]=0;
        Ti[i]=min(Ti[i+1]+1,Ti[i]);
    }
    for(int i=1;i<=n;i++) cout<<Ti[i]<<" ";
    return 0;
}
