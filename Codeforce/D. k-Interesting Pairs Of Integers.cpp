#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll n,cnt[10005]={0},Ti=0,k,t,mn=1e9,mx=-1;
int bitDif(int x,int y){
    int res=0;
    while(x||y){
        if(x%2!=y%2) res++;
        x/=2;
        y/=2;
    }
    return res;
}
int main(){
    //cout<<bitDif(1,4)<<endl;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>t;
        cnt[t]++;
        mn=min(mn,t);
        mx=max(mx,t);
    }
    for(int i=mn;i<=mx;i++){
        if(cnt[i]==0) continue;
        for(int j=i;j<=mx;j++){
            if(cnt[j]==0) continue;
            if(bitDif(i,j)==k&&i!=j) Ti+=cnt[i]*cnt[j];
            else if(bitDif(i,j)==k&&i==j) Ti+=(cnt[i])*(cnt[i]-1)/2;
        }
    }
    cout<<Ti<<endl;
    return 0;
}
