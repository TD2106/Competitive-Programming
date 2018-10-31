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
double h,m,s,t1,t2,posh,posm,poss;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>h>>m>>s>>t1>>t2;
    if(h==double(12)) h=0;
    posh=h*1.0/12.0+(m*1.0/60.0)*1.0/12+(s*1.0/3600.0)*1.0/12;
    posm=m/60.0+s/3600.0;
    poss=s/60.0;
    if(t1==double(12)) t1=0;
    if(t2==double(12)) t2=0;
    t1=t1/12;
    t2=t2/12;
    if(t1<t2) swap(t1,t2);
    if(posh>t2&&posh<t1&&posm>t2&&posm<t1&&poss>t2&&poss<t1){
        cout<<"YES";
        return 0;
    }
    if((posh>t2&&posh<t1)||(posm>t2&&posm<t1)||(poss>t2&&poss<t1)){
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
    return 0;
}
