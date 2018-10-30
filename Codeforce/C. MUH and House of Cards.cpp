#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int main(){
    ll n,Ti=0,t,idx=1;
    cin>>n;
    while(1){
        t=n-2*idx;
        if(t%3==0){
            if(t>=3*idx*(idx-1)/2) Ti++;
        }
        else{
            if(t<3*idx*(idx-1)/2) break;
        }
        idx++;
    }
    cout<<Ti<<endl;
	return 0;
}
