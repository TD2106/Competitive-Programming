#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int n,k,Ti=0,cur=0,remain=0,a;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n&&cur<k;i++){
        cin>>a;
        remain+=a;
        if(remain>8) cur+=8,remain-=8;
        else cur+=remain,remain=0;
        if(cur>=k){
            cout<<i<<endl;
            return 0;
        }
	}
    cout<<-1<<endl;
	return 0;
}
