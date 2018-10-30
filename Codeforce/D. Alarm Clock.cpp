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
int BIT[1000005]={0},n,m,k,t,Ti=0;
void update(int idx,int val){
    while(idx<=1000000){
        BIT[idx]+=val;
        idx+=idx&(-idx);
    }
}
int sum(int idx){
    int res=0;
    while(idx>0){
        res+=BIT[idx];
        idx-=idx&(-idx);
    }
    return res;
}
int range(int l,int r){
    return sum(r) - sum(l-1);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    up(i,1,n){
        cin>>t;
        update(t,1);
    }
    up(i,1,1000000-m+1){
        t=range(i,i+m-1);
        if(t>=k){
            t=t-(k-1);
            Ti+=t;
            down(j,i+m-1,i){
                if(t==0) break;
                int t1=min(range(j,j),t);
                update(j,-t1);
                t-=t1;
            }
        }
    }
    cout<<Ti<<endl;
    return 0;
}
