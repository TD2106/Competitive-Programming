#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
#define M 100005
using namespace std;
typedef long long int ll;
ll tf,ts,t,n,a[M],b[M],mn=1e18,Ti;
int main(){
    cin>>tf>>ts>>t;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(a[0]>tf){
        cout<<tf<<endl;
        return 0;
    }
    b[0]=tf-t;
    for(int i=1;i<=n;i++){
        b[i]=b[i-1]+t;
       // bug(i);
       // bug(b[i]);
        if(b[i]<a[i]&&b[i]+t<=ts){
            cout<<b[i]<<endl;
            return 0;
        }
        if((b[i]-(a[i]-1))<mn&&b[i]+t<=ts){
            mn=b[i]-(a[i]-1);
            Ti=a[i]-1;
        }
    }
    if(b[n]+2*t<=ts){
        cout<<b[n]+t<<endl;
        return 0;
    }
    cout<<Ti<<endl;
    return 0;
}



