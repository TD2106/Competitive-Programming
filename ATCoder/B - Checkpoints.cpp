#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
int main(){
    int n,m,Ti[51]={0},t;
    pii st[51],ck[51];
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>st[i].F>>st[i].S;
    for(int i=1;i<=m;i++) cin>>ck[i].F>>ck[i].S;
    for(int i=1;i<=n;i++){
        int dis=1e9;
        for(int j=1;j<=m;j++){
            t=abs(st[i].F-ck[j].F)+abs(st[i].S-ck[j].S);
            if(t<dis){
                Ti[i]=j;
                dis=t;
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<Ti[i]<<endl;
    return 0;
}
