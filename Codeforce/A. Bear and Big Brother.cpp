#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int main(){
    ll a,b,Ti=0;
    cin>>a>>b;
    while(a<=b){
        Ti++;
        a*=3;
        b*=2;
    }
    cout<<Ti<<endl;
    return 0;
}
