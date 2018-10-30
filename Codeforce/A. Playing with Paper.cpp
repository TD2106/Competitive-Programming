#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int main(){
    ll a,b,Ti=0;
    cin>>a>>b;
    while(a!=0&&b!=0){
        if(a<b) swap(a,b);
        Ti+=a/b;
        a%=b;
    }
    cout<<Ti<<endl;
	return 0;
}
