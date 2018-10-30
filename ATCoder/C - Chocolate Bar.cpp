#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;

int main(){
    ll h,w,s,s1,s2,s3,smax,smin,Ti=1e18;
    cin>>h>>w;
    s=h*w;
    if(s%3==0){
        cout<<0<<endl;
        return 0;
    }
    for(ll i=1;i<=w-1;i++){
        s1=i*h;
        s2=(h/2)*(w-i);
        s3=((h+1)/2)*(w-i);
        smax=max(s1,max(s2,s3));
        smin=min(s1,min(s2,s3));
        Ti=min(smax-smin,Ti);
    }
    for(ll i=1;i<=h-1;i++){
        s1=i*w;
        s2=(w/2)*(h-i);
        s3=((w+1)/2)*(h-i);
        smax=max(s1,max(s2,s3));
        smin=min(s1,min(s2,s3));
        Ti=min(smax-smin,Ti);
    }
    s1=(h/3+1)*w;
    s2=(h/3)*w;
    Ti=min(s1-s2,Ti);
    s1=h*(w/3+1);
    s2=h*(w/3);
    Ti=min(Ti,s1-s2);
    cout<<Ti<<endl;
	return 0;
}
