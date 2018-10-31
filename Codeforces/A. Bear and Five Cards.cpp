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
int t,cnt[105]={0},Ti=0,mx=0;
int main(){
    ios_base::sync_with_stdio(0);
    up(i,1,5){
        cin>>t;
        cnt[t]++;
        Ti+=t;
    }
    up(i,1,100){
        if(cnt[i]>=2){
            mx=max(mx,2*i);
        }
        if(cnt[i]>=3){
            mx=max(mx,3*i);
        }
    }
    Ti-=mx;
    cout<<Ti<<endl;
    return 0;
}
