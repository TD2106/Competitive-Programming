#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
ll Ti=0,n,diagonal,x,y;
bool table[1005][1005];
ll cal(ll x){
    return x*(x-1)/2;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
        cin>>x>>y;
        table[x][y]=1;
	}
	for(int i=1;i<=1000;i++){
        int x=i;
        diagonal=0;
        for(int j=1;j<=1000&&x<=1000;j++,x++){
            diagonal+=(ll)table[x][j];
        }
        Ti+=cal(diagonal);
	}
	//cout<<Ti<<endl;
	for(int i=2;i<=1000;i++){
        int x=i;
        diagonal=0;
        for(int j=1;j<=1000&&x<=1000;j++,x++){
            diagonal+=(ll)table[j][x];
        }
        Ti+=cal(diagonal);
	}
	//cout<<Ti<<endl;
	for(int i=1;i<=1000;i++){
        int x=i;
        diagonal=0;
        for(int j=1;j<=1000&&x>=1;j++,x--){
            diagonal+=(ll)table[j][x];
        }
        Ti+=cal(diagonal);
	}
	//cout<<Ti<<endl;
	for(int i=2;i<=1000;i++){
        int x=i;
        diagonal=0;
        for(int j=1000;j>=1&&x<=1000;j--,x++){
            diagonal+=(ll)table[x][j];
        }
        Ti+=cal(diagonal);
	}
	cout<<Ti<<endl;
	return 0;
}
