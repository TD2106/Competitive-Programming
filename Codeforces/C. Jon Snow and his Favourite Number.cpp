#include <bits/stdc++.h>
#define reset(x) memset(x,0,sizeof(x))
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int fre[2][1024]={0},Tix=0,Tin=1e9,n,k,x,s,t;
int main(){
    cin>>n>>k>>x;
    for(int i=0;i<n;i++) cin>>t,fre[0][t]++;
    for(int i=0;i<k;i++){
        s=0;
        reset(fre[1-i%2]);
        for(int j=0;j<=1023;j++){
            if(fre[i%2][j]==0) continue;
            //cout<<j<<endl;
            //cout<<int(j^x)<<endl;
            //cout<<s<<" "<<j<<endl;
            if(s%2==0){
                fre[1-i%2][j^x]+=(fre[i%2][j]+1)/2;
                fre[1-i%2][j]+=fre[i%2][j]-(fre[i%2][j]+1)/2;
            }
            else{
                fre[1-i%2][j^x]+=(fre[i%2][j])/2;
                fre[1-i%2][j]+=fre[i%2][j]-(fre[i%2][j])/2;
            }
            s+=fre[i%2][j];
        }
    }
    for(int i=0;i<=1023;i++){
        if(fre[k%2][i]){
            Tix=max(i,Tix);
            Tin=min(i,Tin);
        }
    }
    cout<<Tix<<" "<<Tin<<endl;
    return 0;
}
