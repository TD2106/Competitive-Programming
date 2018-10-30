#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int c,l,v0,v1,a,Ti=0,total=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>c>>v0>>v1>>a>>l;
	while(total<c){
        if(total!=0) total-=l;
        total+=min(v0+Ti*a,v1);
        Ti++;
	}
	cout<<Ti<<endl;
	return 0;
}
