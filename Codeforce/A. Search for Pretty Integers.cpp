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
int n,m,a[10],b[10],Ti=0,m1=10,m2=10,cnt[10]={0};
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    up(i,1,n){
        cin>>a[i];
        m1=min(m1,a[i]);
        cnt[a[i]]++;
    }
    up(i,1,m){
        cin>>b[i];
        m2=min(m2,b[i]);
        cnt[b[i]]++;
    }
    if(m1<m2){
        Ti=m1*10+m2;
    }
    else Ti=m2*10+m1;
    up(i,1,9){
        if(cnt[i]==2){
            Ti=i;
            break;
        }
    }
    cout<<Ti<<endl;
    return 0;
}
