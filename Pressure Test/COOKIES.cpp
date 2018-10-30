#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define mp make_pair
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair<double,double> pdd;
pdd nho[205];
int n,Ti=1;
int cnt(pdd center){
    int c=0;
    double t1,t2;
    for(int i=0;i<n;i++){
        t1=center.F-nho[i].F;
        t2=center.S-nho[i].S;
        if((t1*t1+t2*t2)<=6.2500000) c++;
    }
    return c;
}
void bruteForce(){
    double a,b,c,d,e,f,x,y,det;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                //cout<<i<<" "<<j<<" "<<k<<endl;
                a=2*nho[j].F-2*nho[i].F;
                b=2*nho[j].S-2*nho[i].S;
                c=nho[j].F*nho[j].F+nho[j].S*nho[j].S-(nho[i].F*nho[i].F+nho[i].S*nho[i].S);
                d=2*nho[k].F-2*nho[i].F;
                e=2*nho[k].S-2*nho[i].S;
                f=nho[k].F*nho[k].F+nho[k].S*nho[k].S-(nho[i].F*nho[i].F+nho[i].S*nho[i].S);
                det=a*e-b*d;
                //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl;
                if(det!=0){
                    x=(c*e-f*b)/det;
                    y=(a*f-d*c)/det;
                }
                else{
                    if(nho[i].F==nho[j].F==nho[k].F){
                        x=nho[i].F;
                        y=(c-a*x)/b;
                    }
                    else if(nho[i].S==nho[j].S==nho[k].S){
                        y=nho[i].S;
                        x=(c-b*y)/a;
                    }
                }
                //cout<<x<<" "<<y<<endl;
                Ti=max(Ti,cnt(mp(x,y)));
            }
        }
    }
}
int main(){
	//ios_base::sync_with_stdio(0);
	fr("COOKIES.INP");
	fw("COOKIES.OUT");
	while(cin>>nho[n].F>>nho[n].S) n++;
	bruteForce();
	cout<<Ti<<endl;
	return 0;
}
