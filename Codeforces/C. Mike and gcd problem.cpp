#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,cnt=0,Ti=0,g=0,a[100005];
int calculate(int c){
    if(c%2) return c/2+2;
    else return c/2;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        g=__gcd(g,a[i]);
    }
    cout<<"YES"<<endl;
    if(g>1) cout<<0<<endl;
    else{
        for(int i=0;i<n;i++){
            if(a[i]%2) cnt++;
            else{
                Ti+=calculate(cnt);
                cnt=0;
            }
        }
        Ti+=calculate(cnt);
        cout<<Ti<<endl;
    }
    return 0;
}
