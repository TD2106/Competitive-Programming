#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define M 200005
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
int n,a[M]={0},r[M],Ti[M]={0},l[M];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) r[i]=i+1,l[i]=i-1;
    for(int i=1;i<=n;i++) while(a[l[i]]>=a[i]) l[i]=l[l[i]];
    for(int i=n;i>0;i--) while(a[r[i]]>=a[i]) r[i]=r[r[i]];
    for(int i=1;i<=n;i++) Ti[r[i]-l[i]-1]=max(Ti[r[i]-l[i]-1],a[i]);
    for(int i=n;i>=1;i--) Ti[i]=max(Ti[i+1],Ti[i]);
    for(int i=1;i<=n;i++) cout<<Ti[i]<<" ";
    return 0;
}
