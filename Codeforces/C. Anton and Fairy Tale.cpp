#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll n,m,Ti=0,t,temp;
int main(){
    cin>>n>>m;
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    else{
        if(m>=n){
            Ti=n;
            cout<<Ti<<endl;
            return 0;
        }
        else{
            Ti=m+1;
            temp=2*(n-m-1);
            t=(-3+sqrt(9+4*temp))/2;
            //if(t*t+3*t==temp) Ti+=t;
            //else Ti+=t+1;
            while(t*t+3*t<temp) t++;
            Ti+=t;
            cout<<Ti<<endl;
        }
    }
}
