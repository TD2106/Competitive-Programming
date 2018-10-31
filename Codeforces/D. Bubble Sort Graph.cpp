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
typedef vector<int> vi;
typedef pair<int,int> pii;
int bit1[M]={0},bit2[M]={0},a[M],n,Ti=0;
void update(int idx,int val,int bit[]){
    while(idx<=n){
        bit[idx]+=val;
        idx+=idx&(-idx);
    }
}
int query(int idx,int bit[]){
    int res=0;
    while(idx>0){
        res+=bit[idx];
        idx-=idx&(-idx);
    }
    return res;
}
int range(int l,int r,int bit[]){
    return query(r,bit) - query(l-1,bit);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n){
        cin>>a[i];
        update(a[i],1,bit1);
    }
    up(i,1,n){
        update(a[i],-1,bit1);
        Ti=max(Ti,n-(range(1,a[i]-1,bit1)+range(a[i]+1,n,bit2)));
        update(a[i],1,bit2);
        cout<<i<<' '<<Ti<<endl;
    }
    cout<<Ti<<endl;
    return 0;
}
