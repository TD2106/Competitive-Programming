#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll tc,x,y,p,q,Ti,t1,t2,l,r,mid,temp,re;
bool check(ll m){
    //cout<<m<<" "<<endl;
    temp=m*q-y;
    if((x+temp)>=m*p&&m*p>=x) return 1;
    else return 0;
}
ll gcd(ll a,ll b){
    if(a*b==0) return a+b;
    else return gcd(b,a%b);
}
int main(){
    cin>>tc;
    while(tc--){
        cin>>x>>y>>p>>q;
        if(p==0&&x!=0){
            cout<<-1<<endl;
            continue;
        }
        else if(p==0&&x==0){
            cout<<0<<endl;
            continue;
        }
        t1=x/p;
        t2=y/q;
        if(t1>t2){
            re=t1;
            if(x%p) re++;
        }
        else if(t2>t1){
            re=t2;
            if(y%q) re++;
        }
        else{
            re=t1;
            if(x%p||y%q) re++;
        }
        Ti=-1,l=re,r=1e9;
        while(l<=r){
            mid=(l+r)/2;
            if(check(mid)) Ti=mid*q-y,r=mid-1;
            else l=mid+1;
        }
        cout<<Ti<<endl;
    }
	return 0;
}
