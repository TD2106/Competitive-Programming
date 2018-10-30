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
ll a[1000005],st=1,p,q,Ti=0,sum=0,n;
bool flag=0;
int main(){
	ios_base::sync_with_stdio(0);
	fr("BOT.INP");
	fw("BOT.OUT");
	cin>>n;
	up(i,1,n) cin>>a[i];
	up(i,1,n){
        sum+=a[i];
        if(sum>Ti){
            p=st;
            q=i;
            Ti=sum;
            flag=1;
        }
        if(sum<0){
            sum=0;
            st=i+1;
        }
	}
	if(flag) cout<<p<<" "<<q<<" "<<Ti<<endl;
	else{
        Ti=-1e18;
        up(i,1,n){
            if(a[i]>Ti){
                p=q=i;
                Ti=a[i];
            }
        }
        cout<<p<<" "<<q<<" "<<Ti<<endl;
	}
	return 0;
}
