#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int main(){
    int n,k;
    string Ti="";
    cin>>n>>k;
    for(int i=0;i<n;i++) Ti+='a'+(i%k);
    cout<<Ti<<endl;
    return 0;
}
