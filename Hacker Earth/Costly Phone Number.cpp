#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
int minCost[10],a[10],n,tc,idx[10],Ti;
string s;
bool cmp(int b,int c){
    return a[b]<a[c];
}
int main(){
    cin>>tc;
    while(tc--){
        Ti=0;
        for(int i=0;i<10;i++) cin>>a[i],minCost[i]=1e9,idx[i]=i;
        cin>>n>>s;
        sort(idx,idx+10,cmp);
        for(int i=0;i<10;i++){
            minCost[idx[i]]=min(minCost[idx[i]],a[idx[i]]);
            for(int j=0;j<10;j++){
                minCost[(idx[i]+idx[j])%10]=min(minCost[(idx[i]+idx[j])%10],minCost[idx[i]]+minCost[idx[j]]);
            }
        }
        for(int i=0;i<n;i++) Ti+=minCost[s[i]-'0'];
        cout<<Ti<<endl;
    }
    return 0;
}



