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
typedef pair<long double,int> pdi;
ll n,x,y,Tia,Tib;
long double mn=1e9,temp;
vector<pdi> v;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n){
        cin>>x>>y;
        if(x==0){
            if(y>0) v.pb({90,i});
            else v.pb({270,i});
        }
        else{
            temp=atan(abs(y*1.0000000000/x))*180.000000000 / 3.14159265;
            if(x<=0&&y>=0) temp=180.000000000-temp;
            else if(x<=0&&y<=0) temp+=180.000000000;
            else if(x>=0&&y<=0) temp=360.000000000-temp;
//            cout<<x<<' '<<y<<' '<<temp<<endl;
            v.pb({temp,i});
        }
    }
    sort(all(v));
    up(i,0,n-1){
        if(i==0){
            temp=min(abs(v[0].fi-v[n-1].fi),360.000000000-abs(v[0].fi-v[n-1].fi));
            if(temp<mn){
                mn=temp;
                Tia=v[0].se;
                Tib=v[n-1].se;
            }
        }
        else{
            temp=min(abs(v[i].fi-v[i-1].fi),360.000000000-abs(v[i].fi-v[i-1].fi));
            if(temp<mn){
                mn=temp;
                Tia=v[i].se;
                Tib=v[i-1].se;
            }
        }
    }
    cout<<Tia<<' '<<Tib<<endl;
    return 0;
}
