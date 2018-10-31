#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int digit(int a){
    int re=0;
    while(a) re++,a/=10;
    return re;
}
int main(){
    int n,Ti=1,temp;
    cin>>n;
    temp=digit(n);
    if(temp==1) Ti=n+1;
    else{
        temp--;
        while(temp--) Ti*=10;
        Ti*=(n/Ti+1);
    }
    cout<<Ti-n<<endl;
	return 0;
}
