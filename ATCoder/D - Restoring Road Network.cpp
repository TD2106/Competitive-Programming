#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define reset(x) memset(x,0,sizeof(x))
#define up(i,l,r) for(int i=l;i<=r;i++)
#define down(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
typedef long long int ll;
ll n,a[305][305]={0},Ti=0;
bool flag=0;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	up(i,1,n){
        up(j,1,n) cin>>a[i][j];
	}
	up(i,1,n) if(a[i][i]!=0) flag=1;
	up(i,1,n){
        up(j,i+1,n) if(a[i][j]!=a[j][i]) flag=1;
	}
	up(i,1,n){
        up(j,i+1,n){
            bool edge=1;
            up(k,1,n){
                if(k==i||k==j) continue;
                if(a[i][j]>(a[i][k]+a[k][j])){
                    flag=1;
                    break;
                }
                if(a[i][j]==(a[i][k]+a[k][j])) edge=0;
            }
            if(flag) break;
            if(edge) Ti+=a[i][j];
        }
        if(flag) break;
	}
	if(flag) Ti=-1;
	cout<<Ti<<endl;
	return 0;
}
