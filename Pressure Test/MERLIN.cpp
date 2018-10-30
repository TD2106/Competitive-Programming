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
#define M 100005
using namespace std;
typedef long long int ll;
ll a[M]={0},sum=0,Ti,n,temp,l,bottle;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
//	fr("MERLIN.INP");
//	fw("MERLIN.OUT");
    Ti=n-1;
	up(i,1,n){
        cin>>a[i];
        sum+=a[i];
	}
	for(ll i=1;i*i<=sum;i++){
        if(sum%i==0){
            if((sum/i)<=n){
                l=i;
                bottle=sum/i;
                temp=upper_bound(a+1,a+1+n,l)-(a+1);
                if(temp>=bottle) Ti=min(Ti,n-bottle);
            }
            if(i<=n){
                l=sum/i;
                bottle=i;
                temp=upper_bound(a+1,a+1+n,l)-(a+1);
                if(temp>=bottle) Ti=min(Ti,n-bottle);
            }
        }
	}
	cout<<Ti<<endl;
	return 0;
}
