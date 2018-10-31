#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int main(){
    int n;
    double h,area,base=1,tanalpha,delta,t,cur=0;
    vector<double> Ti;
    cin>>n>>h;
    area=h*base/(2.0*n);
    tanalpha=h/0.5;
    n--;
    while(n--){
        delta=base*base-4*area/tanalpha;
        t=(base-sqrt(delta))/2*tanalpha;
        Ti.push_back(h-cur-t);
        cur+=t;
        base=base-2*t/tanalpha;
    }
    reverse(Ti.begin(),Ti.end());
    for(int i=0;i<Ti.size();i++) cout<<fixed<<setprecision(10)<<Ti[i]<<endl;
	return 0;
}
