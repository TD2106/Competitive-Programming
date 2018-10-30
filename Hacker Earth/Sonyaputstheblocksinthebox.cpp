#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
int n,m,len;
vector < vector<ll> > boxes;
vector < vector<ll> > sack;
ll knapsack[101][1001]={0},sum[100001]={0},t,Ti;
int main(){
    cin>>n>>m;
    boxes.resize(n+1);
    sack.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>len;
        reset(sum);
        boxes[i].resize(len+1);
        for(int j=1;j<=len;j++){
            cin>>boxes[i][j];
            sum[j]+=sum[j-1]+boxes[i][j];
        }
       // for(int j=1;j<=len;j++) cout<<sum[j]<<" ";
       // cout<<endl;
        sack[i].pb(0);
        for(int j=1;j<=min(1000,len);j++){
            t=-1e18;
            for(int k=j;k<=len;k++){
                t=max(t,sum[k]-sum[k-j]);
            }
            sack[i].pb(t);
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=0;j<sack[i].size();j++) cout<<sack[i][j]<<" ";
        cout<<endl;
    }*/
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            knapsack[i][j]=max(knapsack[i][j-1],knapsack[i-1][j]);
            for(int k=0;k<=j&&k<sack[i].size();k++)
            knapsack[i][j]=max(knapsack[i][j],sack[i][k]+knapsack[i-1][j-k]);
            //cout<<knapsack[i][j]<<" ";
        }
        //cout<<endl;
    }
    Ti=knapsack[n][m];
    cout<<Ti<<endl;
    return 0;
}
