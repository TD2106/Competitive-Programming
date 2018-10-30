#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll l[3],c[3],n,s,t,Ti[100005]={0},station[100005]={0},temp;
int main(){
    for(int i=0;i<3;i++) cin>>l[i];
    for(int i=0;i<3;i++) cin>>c[i];
    cin>>n>>s>>t;
    station[1]=1;
    if(s>t) swap(s,t);
    for(int i=2;i<=n;i++){
        cin>>temp;
        station[i]=1+temp;
    }
    for(int i=s+1;i<=t;i++){
        Ti[i]=1e18;
        for(int j=i-1;j>=s;j--){
            temp=station[i]-station[j];
            if(temp>l[2]) break;
            if(temp>0&&temp<=l[0]) Ti[i]=min(Ti[i],Ti[j]+c[0]);
            else if(temp>l[0]&&temp<=l[1]) Ti[i]=min(Ti[i],Ti[j]+c[1]);
            else if(temp>l[1]&&temp<=l[2]) Ti[i]=min(Ti[i],Ti[j]+c[2]);
        }
    }
    cout<<Ti[t]<<endl;
	return 0;
}
