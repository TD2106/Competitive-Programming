#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,m,a[1000005]={0},Ti[1000005]={0},q,x,l,r;
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>l>>r;
        a[l]+=1;
        a[r+1]-=1;
    }
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
        Ti[a[i]]++;
    }
    for(int i=m;i>=1;i--) Ti[i]+=Ti[i+1];
    cin>>q;
    while(q--){
        cin>>x;
        cout<<Ti[x]<<endl;
    }
    return 0;
}
