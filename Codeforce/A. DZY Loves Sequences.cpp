#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
#define M 100005
using namespace std;
int a[M]={0},r[M]={0},l[M]={0},Ti=0,n,idx,temp,t;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    l[0]=1,r[n+1]=n;
    a[n+1]=a[n+2]=2e9+5,a[0]=-1;
    for(int i=1;i<=n;i++){
        if(a[i]>a[i-1]) l[i]=l[i-1];
        else l[i]=i;
    }
    for(int i=n;i>=1;i--){
        if(a[i]<a[i+1]) r[i]=r[i+1];
        else r[i]=i;
    }
    for(int i=1;i<=n;i++){
        t=r[i]-l[i]+1;
        //cout<<t<<endl;
        if(i==1){
            temp=1;
            if(r[i]==1) temp=max(temp,r[2]-(2)+1);
            else if((a[r[i]+2]>a[r[i]]+1)||(a[r[i]-1]<a[r[i]+1]-1)) temp=max(temp,r[r[i]+1]-(r[i]+1)-1);
            Ti=max(Ti,t+temp);
        }
        else{
            temp=1;
            if(a[max(l[i]-2,0)]<a[l[i]]-1||a[l[i]+1]>a[l[i]-1]+1) temp=max(temp,l[i]-1-(l[l[i]-1])+1);
            else if((a[r[i]+2]>a[r[i]]+1)||(a[r[i]-1]<a[r[i]+1]-1)) temp=max(temp,r[r[i]+1]-(r[i]+1)-1);
            Ti=max(Ti,t+temp);
        }
        //cout<<temp<<" "<<t<<" "<<Ti<<endl;
        //cout<<i<<" "<<Ti<<endl;
    }
    if(Ti>n) Ti=n;
    cout<<Ti<<endl;
    return 0;
}



