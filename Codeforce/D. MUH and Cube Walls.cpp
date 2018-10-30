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
vector<int> pat,txt,temp;
int n,m,Ti=0,b[200005],t;
void precomputeKMP(){
    int i=0,j=-1;
    b[0]=-1;
    while(i<m){
        while(j>=0&&pat[i]!=pat[j]) j=b[j];
        i++,j++;
        b[i]=j;
    }
}
void KMP(){
    int i=0,j=0;
    while(i<n){
        while(j>=0&&txt[i]!=pat[j]) j=b[j];
        i++,j++;
        if(j==m){
            Ti++;
            j=b[j];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    if(m==1){
        cout<<n<<endl;
        return 0;
    }
    up(i,1,n){
        cin>>t;
        temp.pb(t);
    }
    up(i,1,n-1) txt.pb(temp[i]-temp[i-1]);
    temp.clear();
    up(i,1,m){
        cin>>t;
        temp.pb(t);
    }
    up(i,1,m-1) pat.pb(temp[i]-temp[i-1]);
    n--,m--;
    precomputeKMP();
    KMP();
    cout<<Ti<<endl;
    return 0;
}
