#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long ll;
ll n,k,a[2005]={0},b,Ti=0,maxval = 8000001,cnt[8000005]={0};
bool check[8000005]={0};
ll findIdx(ll val){
    if(val>=0) return val;
    else return val+maxval;
}
int main(){
	ios_base::sync_with_stdio(0);
    cin>>k>>n;
    for(int i=1;i<=k;i++){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++){
        cin>>b;
        for(int j=1;j<=k;j++){
            ll temp = b - a[j];
            if(!check[findIdx(temp)]){
                cnt[findIdx(temp)]++;
                check[findIdx(temp)]=1;
            }
        }
        for(int j=1;j<=k;j++) check[findIdx( b - a[j])]=0;
    }
    //map<ll,ll>::iterator itr;
    for(int i=0;i<=maxval;i++){
        if(cnt[i]==n) Ti++;
    }
    cout<<Ti<<endl;
	return 0;
}
