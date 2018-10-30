#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define pb push_back
#define all(x) x.begin(),x.end()
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
int BIT[100005]={0},n,a[100005],l[100005],r[100005],Ti=0;
void compress(){
    vi temp;
    for(int i=1;i<=n;i++) temp.pb(a[i]);
    sort(all(temp));
    for(int i=1;i<=n;i++) a[i]=lower_bound(all(temp),a[i])-temp.begin()+1;
}
void update(int x,int idx){
    while(idx<=n){
        BIT[idx]+=x;
        idx+=idx&(-idx);
    }
}
int query(int idx){
    int result=0;
    while(idx>0){
        result+=BIT[idx];
        idx-=(idx&(-idx));
    }
    return result;
}
int rangeQuery(int l,int r){
    return query(r)-query(l-1);
}
int main(){
	ios_base::sync_with_stdio(0);
	fr("CHUPANH.INP");
	fw("CHUPANH.OUT");
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	compress();
	reset(BIT);
	for(int i=1;i<=n;i++){
        l[i]=rangeQuery(a[i]+1,n);
        update(1,a[i]);
	}
	reset(BIT);
	for(int i=n;i>=1;i--){
        r[i]=rangeQuery(a[i]+1,n);
        update(1,a[i]);
	}
//	for(int i=1;i<=n;i++) cout<<l[i]<<" "<<r[i]<<endl;
	for(int i=1;i<=n;i++){
        if(min(r[i],l[i])==0&&max(r[i],l[i])!=0) Ti++;
        else if((double)max(r[i],l[i])/(double)min(r[i],l[i])>2) Ti++;
	}
	cout<<Ti<<endl;
	return 0;
}
