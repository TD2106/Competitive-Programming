#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
ll n,m,a[10005],k[105]={0},t;
vector< vector<bool> > Ti;
void display(int idx){
    for(int i=1;i<Ti.size();i++){
        for(int j=0;j<k[idx];j++){
            cout<<Ti[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>k[i];
    for(int i=1;i<=n;i++) cin>>a[i];
  //  cout<<123<<endl;
    for(int i=1;i<=m;i++){
        Ti.resize(n+1);
        for(int j=1;j<=n;j++) Ti[j].resize(k[i]);
        Ti[1][abs(a[1])%k[i]]=1;
        for(int j=2;j<=n;j++){
            t=abs(a[j])%k[i];
            for(ll l=0;l<k[i];l++){
                if(Ti[j-1][l]){
                    Ti[j][(l+t)%k[i]]=1;
                    Ti[j][(l-t+k[i])%k[i]]=1;
                }
            }
        }
        //display(i);
        cout<<Ti[n][0]<<endl;
        Ti.clear();
    }
    return 0;
}
