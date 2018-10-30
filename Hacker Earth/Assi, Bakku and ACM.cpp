#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long int ll;
ll n,c[10001]={0},Ti=0;
int main(){
    for(int i=1;i<=10000;i++) c[i]=1;
    cin>>n;
    for(int i=n;i>=2;i--){
        Ti+=c[i]*(n-c[i])*i;
        c[i/2]+=c[i];
    }
    cout<<Ti<<endl;
    return 0;
}
