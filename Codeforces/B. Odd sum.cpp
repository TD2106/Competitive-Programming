#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int main(){
    int n,t,Ti=0,mn=1e9,mx=-1e9;
    cin>>n;
    while(n--){
        cin>>t;
        if(t>0) Ti+=t;
        if(abs(t)%2==1){
            if(t>0) mn=min(t,mn);
            else mx=max(t,mx);
        }
    }
    if(Ti%2) cout<<Ti<<endl;
    else{
        if(mn==1e9) Ti+=mx;
        else if(mx==1e9) Ti-=mn;
        else Ti=max(Ti+mx,Ti-mn);
        cout<<Ti<<endl;
    }
    return 0;
}
