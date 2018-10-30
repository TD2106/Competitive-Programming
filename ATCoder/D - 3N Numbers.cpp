#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
multiset<ll> pre,suf;
multiset<ll>::iterator itr,temp,mark;
ll n,a[300005],sumpre=0,sumsuf=0,Ti=-1e18,c=0,t;
int main(){
    //freopen("1_16.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=3*n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        pre.insert(a[i]);
        sumpre+=a[i];
    }
    for(int i=n+1;i<=3*n;i++) suf.insert(a[i]);
    for(itr=suf.begin();itr!=suf.end()&&c!=n;itr++){
        sumsuf+=*itr;
        c++;
        mark=itr;
    }
    Ti=max(Ti,sumpre-sumsuf);
    for(int i=n+1;i<=2*n;i++){
        temp=pre.begin();
        t=*temp;
        if(a[i]>t){
            sumpre-=t;
            sumpre+=a[i];
            pre.erase(temp);
            pre.insert(a[i]);
        }
        if(a[i]>*mark) suf.erase(a[i]);
        else{
            mark++;
            sumsuf-=a[i];
            sumsuf+=*mark;
            suf.erase(a[i]);
        }
        Ti=max(sumpre-sumsuf,Ti);
    }
    cout<<Ti<<endl;
	return 0;
}
