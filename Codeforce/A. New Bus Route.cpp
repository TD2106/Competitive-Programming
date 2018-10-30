#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int main(){
    int Ti=2e9+1,a[200005],n,c=0;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n-1;i++){
        int t=a[i+1]-a[i];
        if(t<Ti){
            Ti=t;
            c=1;
        }
        else if(t==Ti) c++;
    }
    cout<<Ti<<" "<<c<<endl;
    return 0;
}
