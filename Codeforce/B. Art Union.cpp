#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int Ti[6]={0},times[6]={0},n,m;
int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>times[j];
            if(Ti[j]<Ti[j-1]) Ti[j] = Ti[j-1];
            Ti[j]+=times[j];
        }
        cout<<Ti[n]<<" ";
    }
    return 0;
}
