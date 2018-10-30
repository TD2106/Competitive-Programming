#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,k,a[205]={0},b[205],cnt[205]={0};
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=k;i++) cin>>b[i];
    if(k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==0) a[i]=b[1];
            if(i!=1){
                if(a[i-1]>a[i]){
                    cout<<"Yes";
                    return 0;
                }
            }
        }
        cout<<"No";
        return 0;
    }
    cout<<"Yes\n";
	return 0;
}
