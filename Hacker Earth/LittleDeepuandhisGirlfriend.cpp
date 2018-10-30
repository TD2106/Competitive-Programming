#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
#define reset(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long int ll;
int tc,n,m,a[100],Ti[100005];
void solve(){
    reset(Ti);
    for(int i=0;i<m;i++) Ti[a[i]]=1;
    for(int i=1;i<=n;i++){
        if(!Ti[i]){
            for(int j=0;j<m;j++){
                if(a[j]<i&&Ti[i-a[j]]==0){
                    Ti[i]=1;
                    break;
                }
            }
        }
    }
}
int main(){
    cin>>tc;
    while(tc--){
        cin>>n>>m;
        for(int i=0;i<m;i++) cin>>a[i];
        solve();
        if(Ti[n]) cout<<"Little Deepu\n";
        else cout<<"Kate\n";
    }
    return 0;
}
