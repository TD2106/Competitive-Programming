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
double R,r,x1,y1,x2,y2,Tix,Tiy,temp;
double distance(double x,double y,double xx,double yy){
    return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>R>>x1>>y1>>x2>>y2;
    if(distance(x1,y1,x2,y2)>=(R-1e-6)){
        cout<<x1<<' '<<y1<<' '<<R<<endl;
        return 0;
    }
    if(x1==x2&&y1==y2){
        cout<<x1+R/2<<' '<<y1<<' '<<R/2<<endl;
        return 0;
    }
    temp=distance(x1,y1,x2,y2)+R;
    r=temp/2;

    return 0;
}
