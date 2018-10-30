#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,m,g[105][105],r[105]={0},c[105]={0},Ti=0,mn;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
             cin>>g[i][j];
        }
    }
    if(n<m){
        for(int i=1;i<=n;i++){
            mn=1000;
            for(int j=1;j<=m;j++){
                mn=min(mn,g[i][j]);
            }
            r[i]=mn;
            Ti+=r[i];
        }
        for(int i=1;i<=m;i++){
            if(g[1][i]>r[1]){
                c[i]=g[1][i]-r[1];
                Ti+=c[i];
            }
        }
    }
    else{
        for(int i=1;i<=m;i++){
            mn=1000;
            for(int j=1;j<=n;j++){
                mn=min(mn,g[j][i]);
            }
            c[i]=mn;
            Ti+=c[i];
        }
        for(int i=1;i<=n;i++){
            if(g[i][1]>c[1]){
                r[i]=g[i][1]-c[1];
                Ti+=r[i];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j]!=r[i]+c[j]){
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    cout<<Ti<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=r[i];j++) cout<<"row "<<i<<endl;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=c[i];j++) cout<<"col "<<i<<endl;
    }
	return 0;
}
