#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int a,b,c,x,y,z,spare=0,need=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>a>>b>>c>>x>>y>>z;
	if(a>x) spare+=(a-x)/2;
	else need+=x-a;
	if(b>y) spare+=(b-y)/2;
	else need+=y-b;
	if(c>z) spare+=(c-z)/2;
	else need+=z-c;
	if(need>spare) cout<<"No";
	else cout<<"Yes";
	return 0;
}
