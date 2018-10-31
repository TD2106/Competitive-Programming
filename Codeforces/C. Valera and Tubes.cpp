#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long int ll;

int main(){
    int n,m,k,l,r,c,dir=1;
    cin>>n>>m>>k;
    l=n*m/k;
    r=c=1;
    for(int i=1;i<=k-1;i++){
        cout<<l<<" ";
        for(int j=0;j<l;j++){
            cout<<r<<" "<<c<<" ";
            c+=dir;
            if(c>m||c<1){
                r++;
                dir*=-1;
                if(c>m) c=m;
                else c=1;
            }
        }
        cout<<endl;
    }
    l+=(n*m)%k;
    cout<<l<<" ";
    for(int j=0;j<l;j++){
        cout<<r<<" "<<c<<" ";
        c+=dir;
        if(c>m||c<1){
            r++;
            dir*=-1;
            if(c>m) c=m;
            else c=1;
        }
    }
    return 0;
}
