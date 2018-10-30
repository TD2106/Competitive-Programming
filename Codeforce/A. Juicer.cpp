#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int n,b,d,a,Ti=0,sum=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>b>>d;
	for(int i=1;i<=n;i++){
        cin>>a;
        if(a>b) continue;
        sum+=a;
        if(sum>d) sum=0,Ti++;
	}
	cout<<Ti<<endl;
	return 0;
}
