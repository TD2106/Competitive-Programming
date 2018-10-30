#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define pb push_back
using namespace std;
typedef long long int ll;
vector<int> prime;
bool isPrime[10005]={0};
int n,a[1005][1005],dis[10005],Ti=1e6,k,temp,Tix,Tiy;
void primeSieve(){
    for(int i=2;i<=10000;i++){
        if(!isPrime[i]){
            for(int j=i*i;j<=10000;j+=i) isPrime[j]=1;
            prime.pb(i);
        }
    }
}
void computeDistance(){
    for(int i=0;i<=10000;i++) dis[i]=1e6;
    for(int i=0;i<prime.size();i++){
        dis[prime[i]]=0;
        for(int j=1;prime[i]-j*k>=0;j++) dis[prime[i]-j*k]=min(dis[prime[i]-j*k],j);
    }
}
int main(){
    cin>>n>>k;
    primeSieve();
    computeDistance();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            if(i==0||i==n+1||j==0||j==n+1) a[i][j]=1e6;
            else a[i][j]=dis[a[i][j]];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            temp=a[i][j]+a[i+1][j+1]+a[i+1][j-1]+a[i-1][j-1]+a[i-1][j+1];
            if(temp<Ti){
                Ti=temp;
                Tix=i;
                Tiy=j;
            }
        }
    }
    if(Ti==1e6) cout<<"no\n";
    else{
        cout<<"yes\n";
        cout<<Ti<<endl;
        cout<<Tix<<" "<<Tiy<<endl;
    }
	return 0;
}
