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
ll n,k,cnt[7]={0},t,Ti;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
    t=n;
    while(t%2==0||t%5==0){
        if(t%2==0){
            t/=2;
            cnt[2]++;
        }
        if(t%5==0){
            t/=5;
            cnt[5]++;
        }
    }
    Ti=n;
    while(cnt[2]<k) Ti*=2,cnt[2]++;
    while(cnt[5]<k) Ti*=5,cnt[5]++;
    cout<<Ti<<endl;
	return 0;
}
