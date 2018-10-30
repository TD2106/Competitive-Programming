#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ull n,k,Ti=0,t1,t2;
int main(){
    cin>>n>>k;
    if(n<k*(k+1)/2){
        cout<<-1<<endl;
        return 0;
    }
    for(ull i=1;i*i<=n;i++){
        if(n%i==0){
            t1=i;
            if((k-1)*k*t1/2<n) t2=n-(k-1)*k*t1/2;
            else t2=0;
            if(t2>(k-1)*t1&&t2%t1==0) Ti=max(Ti,t1);
            t1=n/i;
            if((k-1)*k*t1/2<n) t2=n-(k-1)*k*t1/2;
            else t2=0;
            if(t2>(k-1)*t1&&t2%t1==0) Ti=max(Ti,t1);
        }
    }
    if(Ti==0){
        cout<<-1<<endl;
        return 0;
    }
    for(ull i=1;i<=k;i++){
        if(i!=k)  cout<<Ti*i<<" ";
        else cout<<n-(k-1)*k*Ti/2<<endl;
    }
}
