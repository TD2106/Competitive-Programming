#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,a[105]={0},s=0,idx;
bool vis[105]={0};
int Ti(){
    int r=0;
    for(int i=1;i<=n;i++) if(!vis[i]) r++;
    return r;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],s+=a[i];
    if(a[1]==0||s<n-1) cout<<-1<<endl;
    else{
        cout<<n-1<<endl;
        vis[1]=1;
        int remain = Ti();
        while(remain){
            for(int i=1;i<=n;i++){
                if(vis[i]&&a[i]){
                    idx=i;
                    break;
                }
            }
            for(int i=1;i<=n&&a[idx];i++){
                if(!vis[i]&&a[i]!=0){
                    cout<<idx<<" "<<i<<endl;
                    a[idx]--;
                    vis[i]=1;
                }
            }
            for(int i=1;i<=n&&a[idx];i++){
                if(!vis[i]&&a[i]==0){
                    cout<<idx<<" "<<i<<endl;
                    a[idx]--;
                    vis[i]=1;
                }
            }
            remain = Ti();
        }
    }
    return 0;
}
