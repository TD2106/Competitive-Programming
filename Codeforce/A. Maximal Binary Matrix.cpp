#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,k,r=2,c=2,idxMain=1;
bool Ti[101][101]={0};
int main(){
    cin>>n>>k;
    if(n*n<k){
        cout<<-1<<endl;
        return 0;
    }
    //cout<<123<<endl;
    while(k!=0&&idxMain<=n){
        Ti[idxMain][idxMain]=1;
        k--;
        while(k>=2&&r<=n&&c<=n&&k>0){
            Ti[idxMain][c]=1;
            Ti[r][idxMain]=1;
            k-=2;
            r++,c++;
        }
        idxMain++;
        r=c=idxMain+1;
    }
    if(k!=0) cout<<-1<<endl;
    else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) cout<<Ti[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
