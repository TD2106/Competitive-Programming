#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define M 200005
#define F first
#define S second
using namespace std;
typedef long long int ll;
pair<int,int> chess[M],pro[M];
int n,m,Ti=0;
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.S<b.S;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>chess[i].F>>chess[i].S;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>pro[i].F>>pro[i].S;
    }
    sort(chess,chess+n,cmp);
    sort(pro,pro+m);
    //cout<<pro[m-1].F<<endl;
    //cout<<chess[0].S<<endl;
    Ti=max(0,pro[m-1].F-chess[0].S);
    sort(pro,pro+m,cmp);
    sort(chess,chess+n);
    Ti=max(Ti,chess[n-1].F-pro[0].S);
    cout<<Ti<<endl;
    return 0;
}
