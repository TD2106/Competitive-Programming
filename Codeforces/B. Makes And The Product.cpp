#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll n,Ti=1,mod=1e9+7,t,num=0;
map<ll,ll> cnt;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        cnt[t]++;
    }
    map<ll,ll>::iterator itr;
    for(itr=cnt.begin();itr!=cnt.end()&&num<3;itr++){
        if(itr->second+num>3){
            t=3-num;
            if(t==1) Ti*=itr->second;
            else if(t==2) Ti*=(itr->second)*(itr->second-1)/2;
            else if(t==3) Ti*=(itr->second)*(itr->second-1)*(itr->second-2)/6;
        }
        num+=itr->second;
    }
    cout<<Ti<<endl;
	return 0;
}
