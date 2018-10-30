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
typedef vector<int> vi;
typedef pair<int,int> pii;
int n,Ti=0,a[2005],cnt[2005]={};
int maxConnection(){
    int res=-1,mx=0;
    up(i,1,n){
        if(cnt[i]>mx&&cnt[i]!=0){
            mx=cnt[i];
            res=i;
        }
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    up(i,1,n){
        up(j,1,n) if(abs(a[i]-a[j])==1||abs(a[i]-a[j])==8||abs(a[i]-a[j])==9) cnt[i]++;
    }
    int idx=maxConnection();
    while(idx!=-1){
        up(i,1,n){
            if(abs(a[i]-a[idx])==1||abs(a[i]-a[idx])==8||abs(a[i]-a[idx])==9) cnt[i]--;
        }
        cnt[idx]=0;
        Ti++;
        idx=maxConnection();
    }
    cout<<Ti<<endl;
}
