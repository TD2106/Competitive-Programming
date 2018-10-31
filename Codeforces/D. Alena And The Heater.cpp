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
int n,a[100005],b[100005]={0},cntb[5]={0},l,r,mx[100005],mn[100005],upr=1e9,downr=-1e9,upl=1e9,downl=-1e9;
string s;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n) cin>>a[i];
    cin>>s;
    up(i,1,n) b[i]=s[i-1]-'0';
    up(i,1,4) cntb[b[i]]++;
    up(i,5,n){
        int m1=1e9,m2=-1e9;
        down(j,i,i-4){
            m1=min(m1,a[j]);
            m2=max(m2,a[j]);
        }
        mx[i]=m2;
        mn[i]=m1;
    }
    up(i,5,n){
        if(cntb[0]==4){
            if(b[i]==1){
                downl=max(downl,mx[i]+1);
            }
        }
        else if(cntb[1]==4){
            if(b[i]==0){
                upr=min(upr,mn[i]-1);
            }
        }
        cntb[b[i-4]]--;
        cntb[b[i]]++;
    }
    cout<<downl<<' '<<upr<<endl;
    return 0;
}
