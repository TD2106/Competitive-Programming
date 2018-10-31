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
int n,dsu[105],Ti=0,x[105],y[105];
int find(int x){
    if(x==dsu[x]) return x;
    else return dsu[x]=find(dsu[x]);
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    dsu[x]=y;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    up(i,1,n){
        cin>>x[i]>>y[i];
        dsu[i]=i;
    }
    up(i,1,n){
        up(j,1,i-1){
            if(x[i]==x[j]||y[i]==y[j]) merge(i,j);
        }
    }
    up(i,1,n){
        if(dsu[i]==i) Ti++;
    }
    Ti--;
    cout<<Ti<<endl;
    return 0;
}
