#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
ll l,r,x,y,Ti=0,temp;
vector<ll> xpow,ypow;
vector<ll> unlucky;
void precompute(ll a,vector<ll> &apow){
    temp=1;
    while(1){
        apow.push_back(temp);
        if(temp>r/a) break;
        temp*=a;
    }
}
int main(){
    cin>>x>>y>>l>>r;
    precompute(x,xpow);
    precompute(y,ypow);
    for(int i=0;i<xpow.size();i++){
        for(int j=0;j<ypow.size();j++){
            temp=xpow[i]+ypow[j];
            //cout<<temp<<" "<<i<<" "<<j<<endl;
            if(temp>=l&&temp<=r) unlucky.push_back(temp);
        }
    }
    unlucky.push_back(l-1);
    unlucky.push_back(r+1);
    sort(unlucky.begin(),unlucky.end());
    for(int i=1;i<unlucky.size();i++){
        temp=unlucky[i]-unlucky[i-1]-1;
        Ti=max(Ti,temp);
    }
    if(unlucky.size()==0) Ti=r-l+1;
    cout<<Ti<<endl;
	return 0;
}
