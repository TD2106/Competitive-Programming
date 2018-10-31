#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define M 1000005
using namespace std;
typedef long long int ll;
ll n,a[M]={0},l[M],r[M],Ti=0;
void reset(){
    for(int i=1;i<=n;i++) l[i]=i-1,r[i]=i+1;
    l[0]=0;
    l[n+1]=n+1;
}
int main(){

    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    reset();
    a[0]=a[n+1]=1e8;
    for(int i=1;i<=n;i++){
        while(a[l[i]]<a[i]) l[i]=l[l[i]];
    }
    for(int i=n;i>=1;i--){
        while(a[r[i]]<=a[i]) r[i]=r[r[i]];
    }
    for(int i=1;i<=n;i++){
        //cout<<(i-l[i])*(r[i]-i)<<endl;
        Ti+=(i-l[i])*(r[i]-i)*a[i];
    }
    reset();
    a[0]=a[n+1]=-1;
    for(int i=1;i<=n;i++){
        while(a[l[i]]>a[i]) l[i]=l[l[i]];
    }
    for(int i=n;i>=1;i--){
        while(a[r[i]]>=a[i]) r[i]=r[r[i]];
    }
    for(int i=1;i<=n;i++){
        //cout<<(i-l[i])*(r[i]-i)<<endl;
        Ti-=(i-l[i])*(r[i]-i)*a[i];
    }
    cout<<Ti<<endl;
	return 0;
}
