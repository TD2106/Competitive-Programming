#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int main(){
    int n,Ti;
    cin>>n;
    Ti=n/2;
    if(n%2==0) Ti-=1;
    cout<<Ti<<endl;
	return 0;
}
