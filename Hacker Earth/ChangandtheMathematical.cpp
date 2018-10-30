#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,cnt[10005]={0},Ti=1e9,t;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        cnt[t]++;
    }
    for(int i=1;i<=1e4;i++) cnt[i]+=cnt[i-1];
    for(int i=1;i<=1e4;i++) Ti=min(Ti,n-(cnt[min(10000,3*i)]-cnt[i-1]));
    cout<<Ti<<endl;
    return 0;
}
