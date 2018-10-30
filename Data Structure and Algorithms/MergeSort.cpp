#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int a[10],res[10],c=0;
void mergearr(int l,int mid,int r){
    int i1=l,i2=mid,idx=l;
    while(i1<mid||i2<=r){
        if(i1==mid) res[idx++]=a[i2++];
        else if(i2>r) res[idx++]=a[i1++],c++;
        else if(a[i1]<=a[i2]) res[idx++]=a[i1++];
        else res[idx++]=a[i2++],c++;
    }
    for(int i=l;i<=r;i++) a[i]=res[i];
}
void divide(int l,int r){
   // cout<<l<<" "<<r<<endl;
    if(l==r) return;
    else{
        divide(l,(l+r)/2);
        divide((l+r)/2+1,r);
        mergearr(l,(l+r)/2+1,r);
    }
}
int main(){
    for(int i=0;i<9;i++) cin>>a[i];
    divide(0,8);
    for(int i=0;i<9;i++) cout<<res[i]<<" ";
    cout<<endl;
    cout<<c<<endl;
    return 0;
}
