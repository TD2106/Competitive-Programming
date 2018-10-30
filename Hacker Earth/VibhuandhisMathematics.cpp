#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define mod 1000000007
using namespace std;
typedef long long int ll;
ll tc,n,Ti[1000005]={0};
int main(){
    Ti[1]=1;
    Ti[2]=2;
    for(int i=3;i<=1e6;i++){
        Ti[i]=Ti[i-1]%mod+((i-1)*Ti[i-2]%mod)%mod;
        Ti[i]%=mod;
    }
    cin>>tc;
    while(tc--){
        cin>>n;
        cout<<Ti[n]<<endl;
    }
    return 0;
}
