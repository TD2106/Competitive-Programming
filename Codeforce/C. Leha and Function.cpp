#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
int n,a[200005],Ti[200005];
pii b[200005];
int main(){
	ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>b[i].first;
        b[i].second=i;
    }
    sort(a+1,a+1+n,greater<int>());
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++){
        Ti[b[i].second]=a[i];
    }
    for(int i=1;i<=n;i++) cout<<Ti[i]<<" ";
	return 0;
}
