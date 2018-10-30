#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int Ti[60001]={0},n,t[60001],r[60001];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>t[i];
    for(int i=1;i<=n-1;i++) cin>>r[i];
    Ti[1]=t[1];
    for(int i=2;i<=n;i++){
        Ti[i]=min(t[i]+Ti[i-1],r[i-1]+Ti[i-2]);
    }
    cout<<Ti[n]<<endl;
    return 0;
}
