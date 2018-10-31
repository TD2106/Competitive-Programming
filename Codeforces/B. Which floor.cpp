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
typedef pair<int,int> pii;
int n,m,Ti=0;
pii flat[105];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	if(n==1){
        cout<<1<<endl;
        return 0;
	}
	if(m==0&&n!=1){
        cout<<-1<<endl;
        return 0;
	}
	up(i,1,m) cin>>flat[i].fi>>flat[i].se;
	up(i,1,100){
        bool flag=1;
        up(j,1,m){
            if(!((flat[j].fi>=(flat[j].se-1)*i+1)&&(flat[j].fi<=flat[j].se*i))){
                flag=0;
                break;
            }
        }
        if(flag){
            if(Ti==0) Ti=n/i+bool(n%i);
            else if(Ti!=(n/i+bool(n%i))){
                cout<<-1<<endl;
                return 0;
            }
        }
	}
	if(Ti==0) Ti=-1;
	cout<<Ti<<endl;
	return 0;
}
