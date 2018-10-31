#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define M 1000000
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long int ll;
ll n,a[1000005],BIT[1000005],Ti=0,cnt[1000005]={0},ffront[1000005]={0},fback[1000005]={0};
vector<int> num;
vector<int>::iterator itr;
void update(int x,int idx){
    while(idx<=M){
        BIT[idx]+=x;
        idx+=idx&(-idx);
    }
}
int query(int idx){
    int sum=0;
    while(idx>0){
        sum+=BIT[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}
int main(){
	ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        num.push_back(a[i]);
    }
    sort(num.begin(),num.end());
    for(int i=1;i<=n;i++){
        itr=lower_bound(num.begin(),num.end(),a[i]);
        a[i]=itr-num.begin()+1;
    }
    for(int i=1;i<=n;i++){
        cnt[a[i]]++;
        ffront[i]=cnt[a[i]];
        update(1,ffront[i]);
    }
    reset(cnt);
    for(int i=n;i>=1;i--){
        cnt[a[i]]++;
        fback[i]=cnt[a[i]];
        update(-1,ffront[i]);
        Ti+=((ll)query(M)-(ll)query(fback[i]));
    }
    cout<<Ti<<endl;
	return 0;
}
