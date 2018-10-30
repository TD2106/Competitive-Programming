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
int BIT[100005],n,k,r,Ti=0;
void update(int idx,int x){
    while(idx<=n){
        BIT[idx]+=x;
        idx+=(idx&(-idx));
    }
}
int sum(int idx){
    int res=0;
    while(idx>0){
        res+=BIT[idx];
        idx-=(idx&(-idx));
    }
    return res;
}
int range(int l,int r){
    return sum(r)-sum(l-1);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k>>r;
	up(i,1,k){
        int temp;
        cin>>temp;
        update(temp,1);
    }
    up(i,1,n-r+1){
        if(range(i,i+r-1)<2){
            int temp=2-range(i,i+r-1);
            down(j,i+r-1,i){
                if(range(j,j)==0){
                    update(j,1);
                    Ti++;
                    temp--;
                }
                if(temp==0) break;
            }
        }
    }
    cout<<Ti<<endl;
	return 0;
}
