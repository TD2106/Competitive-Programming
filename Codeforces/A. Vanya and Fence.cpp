#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,Ti=0,a,h;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>h;
	for(int i=1;i<=n;i++){
        cin>>a;
        if(a<=h) Ti++;
        else Ti+=2;
	}
	cout<<Ti<<endl;
	return 0;
}
