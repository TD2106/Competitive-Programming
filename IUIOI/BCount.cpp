#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int Ti[4][100005]={0},n,q,x,y;
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++) Ti[j][i]=Ti[j][i-1];
        cin>>x;
        Ti[x][i]++;
    }
    while(q--){
        cin>>x>>y;
        for(int i=1;i<=3;i++) cout<<Ti[i][y]-Ti[i][x-1]<<" ";
        cout<<endl;
    }
	return 0;
}
