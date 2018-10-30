#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
int n,Ti[101][101],c[101],sum[101];
int color(int j,int i){
    return (sum[j]-sum[i-1])%100;
}
int main(){
    while(cin>>n){
        reset(Ti);
        reset(c);
        reset(sum);
        for(int i=1;i<=n;i++){
            cin>>c[i];
            sum[i]=sum[i-1]+c[i];
        }
        for(int l=2;l<=n;l++){
            for(int i=1;i<=n-l+1;i++){
                int j=l+i-1;
                Ti[i][j]=1e9;
                for(int k=i;k<j;k++){
                    Ti[i][j]=min(Ti[i][j],Ti[i][k]+Ti[k+1][j]+color(k,i)*color(j,k+1));
                }
            }
        }
        cout<<Ti[1][n]<<endl;
    }
	return 0;
}
