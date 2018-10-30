#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll n,x,Ti=0,iceCream;
char sign;
int main(){
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>sign>>iceCream;
        if(sign=='+') x+=iceCream;
        else{
            if(x>=iceCream) x-=iceCream;
            else Ti++;
        }
    }
    cout<<x<<" "<<Ti<<endl;
	return 0;
}
