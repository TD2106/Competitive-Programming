#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,a[101]={0},l=0,dp[101]={0};
string Ti;
void toBinary(int x){
    if(!x) return;
    else{
        toBinary(x/2);
        Ti+='0'+x%2;
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        dp[i]=1;
        for(int j=i-1;j>0;j--){
            if(a[j]<a[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        l=max(l,dp[i]);
    }
    toBinary(l);
    cout<<Ti<<endl;
    return 0;
}
