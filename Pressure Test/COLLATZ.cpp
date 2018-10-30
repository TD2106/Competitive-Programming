#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll Ti=0,n,temp,odd,even,t;
int main(){
	//ios_base::sync_with_stdio(0);
	freopen("COLLATZ.INP","r",stdin);
	freopen("COLLATZ.OUT","w",stdout);
	cin>>n;
	temp=n-1;
	temp=(temp/3)+1;
	if(temp%2==0) temp+=1;
	t=n;
	if(t%2==0) t-=1;
	Ti+=(t+1)/2-(temp+1)/2+1;
	temp=n/2+1;
	Ti+=n-temp+1;
	cout<<Ti<<endl;
	return 0;
}
