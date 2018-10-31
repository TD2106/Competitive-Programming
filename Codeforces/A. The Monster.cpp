#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int a,b,c,d,Ti=0;
int main(){
    cin>>a>>b>>c>>d;
    for(Ti=max(b,d);Ti<=1e5;Ti++){
        if((Ti-b)%a==0&&(Ti-d)%c==0){
            cout<<Ti<<endl;
            return 0;
        }
    }
    Ti=-1;
    cout<<Ti<<endl;
    return 0;
}
