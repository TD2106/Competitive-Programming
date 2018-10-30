#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
int main(){
    ll n,m,Ti=1e9;
    cin>>n>>m;
    Ti=max(2*n,3*m);
    while(Ti/3+Ti/2-Ti/6<n+m) Ti++;
    cout<<Ti<<endl;
    return 0;
}



