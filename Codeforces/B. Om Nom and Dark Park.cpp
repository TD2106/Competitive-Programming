#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll n,a[2050]={0},Ti=0,node=1;
int main(){
    cin>>n;
    for(int i=1;i<=n+1;i++) node*=2;
    node--;
   //cout<<node<<endl;
    for(int i=2;i<=node;i++) cin>>a[i];
    for(int i=node;i>1;i-=2){
        Ti+=abs(a[i]-a[i-1]);
        a[i/2]+=max(a[i],a[i-1]);
    }
    cout<<Ti<<endl;
    return 0;
}
