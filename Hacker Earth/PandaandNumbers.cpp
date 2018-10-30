#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
bool dp[1000005]={0};
int tc,n;
bool solve(int x){
    if(dp[x]) return 1;
    int temp=x,t;
    while(temp){
        t=temp%10;
        if(x-t*t>0&&dp[x-t*t]==1) return 1;
        temp/=10;
    }
    return 0;
}
int main(){
    for(int i=1;i<=7;i++) dp[(int)pow(i,i)]=1;
    for(int i=1;i<=1e6;i++) dp[i]=solve(i);
    cin>>tc;
    while(tc--){
        cin>>n;
        if(dp[n]) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
