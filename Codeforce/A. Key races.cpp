#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int s,v1,v2,t1,t2,Tione,Titwo;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>s>>v1>>v2>>t1>>t2;
	Tione=t1+s*v1+t1;
	Titwo=2*t2+s*v2;
	if(Tione==Titwo) cout<<"Friendship";
	else if(Tione<Titwo) cout<<"First";
	else cout<<"Second";
	return 0;
}
