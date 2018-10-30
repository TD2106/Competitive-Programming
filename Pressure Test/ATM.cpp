#include <bits/stdc++.h>

#define bug(x) cout << #x << " = " << x << endl;
#define fr(a) freopen(a,"r",stdin);
#define fw(a) freopen(a,"w",stdout);
#define tc() int tc;cin >> tc; for (int _tc=1;_tc<=tc;_tc++)
#define up(i,l,r) for (ll i=l;i<=r;i++)
#define down(i,r,l) for (int i=r;i>=l;i--)
#define rep(i,l,r) for (int i=l;i<r;i++)
#define pb push_back
#define mp make_pair
#define ins insert
#define fi first
#define se second
using namespace std;
typedef long long int ll;
typedef unsigned long long int llu;
typedef pair<int,int> ii;

/****************************************************/
void printArr(int a[], int l, int r)
{
    up(i,l,r) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void printMtx(int a[][1010],int n, int m)
{
    up(i,1,n) {
        up(j,1,m) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
/****************************************************/
map<ll,ll> cnt,memo;
ll soluong[] = {0,1,1,1,2,1,2,2,2,3,2};
ll cach[] =    {0,1,1,1,2,1,2,1,1,3,1};
ll w,c,resN=0,resS=1,mx;
vector<ll> decompose;
void Init()
{
    up(i,0,c) {
        up(j,1,10){
            ll t=j*1000*pow(10,i);
            cnt[t]=soluong[j];
            memo[t]=cach[j];
            mx=t;
        }
    }
}
void tach(ll x){
    ll t=1;
    while(x){
        decompose.push_back(t*(x%10));
        t*=10;
        x/=10;
    }

}
void process(ll x){
    //cout<<x<<endl;
    if(x<1000) return;
    map<ll,ll>::iterator itr;
    itr=cnt.end();
    itr--;
    while(x<itr->first) itr--;
    resN+=x/(itr->first)*(itr->second);
    resS*=memo[itr->first];
    //cout<<resN<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    //fr("ATM.INP");
    //fw("ATM.OUT");
    cin>>w>>c;
    if(w%1000) cout<<0<<endl;
    else{
        Init();
        tach(w);
        //for(int i=0;i<decompose.size();i++) cout<<decompose[i]<<endl;
        for(int i=0;i<decompose.size();i++){
            process(decompose[i]);
        }
        if(w==mx+mx/10) resS+=1;
        if(w==mx+mx/10*4) resS+=1;
        cout<<resN<<" "<<resS<<endl;
    }
}
