#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int r1,c1,r2,c2,n,m,Ti=0;
char table[505][505]={0};
void flood(int r,int c){
    //cout<<r<<" "<<c<<endl;
    if(Ti) return;
    if(r==r2&&c==c2&&table[r][c]=='X'){
        Ti=1;
        return;
    }
    else{
        if(table[r][c]=='X'||table[r][c]==0) return;
        else if (table[r][c]=='.'){
            table[r][c]='X';
            flood(r+1,c);
            flood(r-1,c);
            flood(r,c+1);
            flood(r,c-1);
            return;
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>table[i][j];
    }
    cin>>r1>>c1>>r2>>c2;
    table[r1][c1]='.';
    flood(r1,c1);
    if(Ti) cout<<"YES";
    else cout<<"NO";
    return 0;
}
