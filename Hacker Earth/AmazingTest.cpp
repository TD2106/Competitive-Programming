#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
#define reset(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long int ll;
int tc,x,n,d1,d2,a[101],flag,s,t;
bool check[10001][101]={0},Ti;
bool subSetSum(int sum,int mx){
    for(int i=0;i<=n;i++) check[0][i]=1;
    for(int i=1;i<=mx;i++){
        for(int j=1;j<=n;j++){
            check[i][j]=check[i][j-1];
            if(a[j]<=i) check[i][j]|=check[i-a[j]][j-1];
            if(i>=sum&&check[i][j]) return 1;
        }
    }
    return 0;
}
int main (){
    cin>>tc;
    while(tc--){
        Ti=s=0;
        cin>>n>>x;
        for(int i=1;i<=n;i++) cin>>a[i],s+=a[i];
        if(s==0) cout<<"YES\n";
        else if((s+1)/2>x) cout<<"NO\n";
        else{
            reset(check);
            Ti=subSetSum((s+1)/2,min(x,s));
            if(Ti) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}
