#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,k,w[100005]={0},idx=1,Ti=0,t,avai;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>w[i];
    sort(w+1,w+1+n);
    for(int i=1;i<=n;i++){
        if(w[i]<=k){
            w[i]=0;
            Ti++;
            if(w[i+1]<=k) w[++i]=0;
            else w[i+1]-=k;
        }
        else{
            t=w[i]/k;
            if(t%2==1&&w[i]%k!=0) Ti+=(t+1)/2,w[i]=0;
            else if(t%2==1&&w[i]%k==0) w[i]=0,Ti+=(t+1)/2,w[i+1]-=k;
            else if(t%2==0&&w[i]%k!=0) Ti+=t/2+1,w[i]=0,w[i+1]-=k;
            else if(t%2==0&&w[i]%k==0) Ti+=t/2;
        }
    }
    cout<<Ti<<endl;
    return 0;
}
