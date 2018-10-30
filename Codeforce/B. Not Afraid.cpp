#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
int n,m,k,x;
set<int> Ti;
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        set<int> check;
        cin>>k;
        while(k--){
            cin>>x;
            check.insert(x);
            if(check.count(x)&&check.count(-x)) Ti.insert(i);
        }
    }
    if(Ti.size()==m) cout<<"NO\n";
    else cout<<"YES\n";
    return 0;
}
