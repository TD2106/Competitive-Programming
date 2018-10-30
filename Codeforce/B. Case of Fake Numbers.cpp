#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int main(){
    int n,Ti[1005],rotation;
    cin>>n;
    for(int i=0;i<n;i++) cin>>Ti[i];
    rotation=n-(Ti[0]%n);
    for(int i=0;i<n;i++){
        if(i%2==0) Ti[i]=(Ti[i]+rotation)%n;
        else Ti[i]=(Ti[i]-rotation+n)%n;
        if(Ti[i]!=i){
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n";
	return 0;
}
