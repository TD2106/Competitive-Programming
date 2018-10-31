#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define M 100005
using namespace std;
typedef long long int ll;
ll n,k,Ti=0,a[M];
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=1;i<n;i++){
        if((a[i]-a[i-1])%k!=0){
            cout<<-1<<endl;
            return 0;
        }
        else{
            Ti+=(a[i]-a[i-1])/k;
            a[i]=a[i-1];
        }
    }
    cout<<Ti<<endl;
    return 0;
}
