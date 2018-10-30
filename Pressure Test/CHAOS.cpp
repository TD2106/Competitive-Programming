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
ll a,b,c,d,k,Ti=0,day=1,temp;
int main(){
	ios_base::sync_with_stdio(0);
	fr("CHAOS.INP");
	fw("CHAOS.OUT");
	cin>>a>>b>>c>>d>>k;
	while(Ti<d&&day<=k){
        temp=a*b;
        if(temp<=c){
            Ti=0;
            break;
        }
        else{
            temp-=c;
            Ti=min(temp,d);
            a=Ti;
        }
        day++;
	}
	cout<<Ti<<endl;
	return 0;
}
