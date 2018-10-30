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
int n,x[100005]={0},y[100005]={0},Ti=0;
string s;
int side(int xx,int yy){
    return (xx-yy);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>s;
    up(i,0,s.size()-1){
        x[i+1]=x[i];
        y[i+1]=y[i];
        if(s[i]=='U') y[i+1]++;
        else x[i+1]++;
//        cout<<x[i+1]<<' '<<y[i+1]<<endl;
        if(i>=2){
            if(side(x[i],y[i])==0&&side(x[i-1],y[i-1])*side(x[i+1],y[i+1])<0) Ti++;
        }
    }
    cout<<Ti<<endl;
    return 0;
}
