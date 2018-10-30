#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl;
#define fr(a) freopen(a,"r",stdin);
#define fw(a) freopen(a,"w",stdout);
#define tc() int tc;cin >> tc; for(int _tc=1;_tc<=tc;_tc++)
#define up(i,l,r) for (int i=l;i<=r;i++)
#define down(i,r,l) for (int i=r;i>=l;i--)
#define rep(i,l,r) for (int i=l;i<r;i++)
#define all(x) x.begin(),x.end()
#define reset(x) memset(x,0,sizeof(x))
#define pb push_back
#define mp make_pair
#define ins insert
#define fi first
#define se second
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

/****************************************************/
void printArr(int a[], int l, int r)
{ up(i,l,r) cout << a[i] << " \n"[i==r]; }

void printMtx(int a[][1010],int n, int m)
{ up(i,1,n) up(j,1,m) cout << a[i][j] << " \n"[j==m]; }
/****************************************************/

vector<pii> a;
int BIT[100005]={0},M=100000,n,p,last=0;
ll Ti=0;
void update(int idx,int val){
    while(idx<=M){
        BIT[idx]+=val;
        idx+=idx&(-idx);
    }
}
int query(int idx){
    int res=0;
    while(idx>0){
        res+=BIT[idx];
        idx-=idx&(-idx);
    }
    return res;
}
int range(int l,int r){
    return query(r)-query(l-1);
}
bool cmp(const pii& a,const pii& b){
    return (a.fi<b.fi||a.fi==b.fi&&a.se>b.se);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    up(i,1,n) {
        cin >> p;
        if((i==1&&p==n)||(i==n&&p==1)||(i==p-1)||(i==p+1)||(i==p)) continue;
        a.pb({min(p,i),max(p,i)});
    }
    sort(a.begin(), a.end(),cmp);
    if(a.size()<=1){
        cout<<0<<endl;
        return 0;
    }
    for(pii t:a){
        Ti+=(ll)range(t.fi+1,t.se-1);
        update(t.se,1);
    }
    cout<<Ti<<endl;
}
