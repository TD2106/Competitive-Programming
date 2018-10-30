#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll n,x,Ti=0;
int main(){
    cin>>n;
    while(n--){
        cin>>x;
        Ti+=--x;
        if(Ti%2) cout<<1<<endl;
        else cout<<2<<endl;
    }
    return 0;
}
