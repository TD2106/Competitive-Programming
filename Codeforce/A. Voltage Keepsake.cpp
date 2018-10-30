#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n;
double p,a[100005],b[100005],sum=0,Ti,pre=0,l,r;
bool check(double mid){
    double total=0;
    for(int i=0;i<n;i++) total+=max(0.0,(mid*a[i]-b[i])/p);
    if(total>mid) return 0;
    else return 1;
}
int main(){
    cin>>n>>p;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        sum+=a[i];
    }
    if(p>=sum){
        cout<<-1<<endl;
        return 0;
    }
    l=0,r=1e18,Ti=(l+r)/2;
    while(abs(Ti-pre)>=0.0001){
        if(check(Ti)) l=Ti;
        else r=Ti;
        pre=Ti;
        Ti=(l+r)/2;
       // cout<<Ti<<" "<<l<<" "<<r<<" "<<pre<<endl;
    }
    cout<<fixed<<setprecision(4)<<Ti<<endl;
    return 0;
}
