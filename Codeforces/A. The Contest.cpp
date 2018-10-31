#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define F first
#define S second
using namespace std;
typedef long long int ll;
int main(){
    int n,m,l,r,Ti=0,t;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        Ti+=t;
    }
    cin>>m;
    while(m--){
        cin>>l>>r;
        if(l<=Ti&&Ti<=r){
             cout<<Ti<<endl;
             return 0;
        }
        else if(l>=Ti){
            cout<<l<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
	return 0;
}
