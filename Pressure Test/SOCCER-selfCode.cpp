#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define F first
#define S second
#define mp make_pair
using namespace std;
typedef long long int ll;
typedef pair<double,double> pdd;
pdd point[105];
bool isSameSide(pdd a,pdd b,pdd c){
    double temp = (a.F-b.F)*(a.F-c.F);
    if(temp<0) return 0;
    temp=(a.S-b.S)*(a.S-c.S);
    if(temp<0) return 0;
    else return 1;
}
bool isAlign(pdd a, pdd b, pdd c){
    double A,B,C;
    A=-(b.S-c.S);
    B=b.F-c.F;
    C=-A*b.F-B*b.S;
    if(A*a.F+B*a.S+C==0.000000) return 1;
    else return 0;
}
pdd projection(pdd a, pdd b, pdd c){
    double x1=b.F, y1=b.S, x2=c.F, y2=c.S, x3=a.F, y3=a.S;
    double px = x2-x1, py = y2-y1, dAB = px*px + py*py;
    double u = ((x3 - x1) * px + (y3 - y1) * py) / dAB;
    double x = x1 + u * px, y = y1 + u * py;
    return mp(x,y);
}
double calDistance(pdd a,pdd b){
    double temp = (a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S);
    return sqrt(temp);
}
int testCase,m;
double n,Ti;
int main(){
	ios_base::sync_with_stdio(0);
	fr("SOCCER.INP");
	fw("SOCCER.OUT");
    cin>>testCase;
    for(int tc=1;tc<=testCase;tc++){
        cin>>n>>m;
        bool flag=0;
        for(int i=1;i<=m;i++) cin>>point[i].F>>point[i].S;
        for(int i=1;i<=m;i++){
            if(!isAlign(mp(0,0),point[i],point[i+1])){
                pdd temp=projection(mp(0,0),point[i],point[i+1]);
                if(!isSameSide(temp,point[i],point[i+1])) Ti=calDistance(temp,mp(0,0));
                else Ti=min(calDistance(mp(0,0),point[i]),calDistance(mp(0,0),point[i+1]));
                if(Ti<=n) flag=1;
            }
        }
        cout<<"Case "<<tc<<": ";
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
	return 0;
}
