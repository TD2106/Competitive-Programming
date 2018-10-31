#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define F first
#define S second
using namespace std;
typedef long long int ll;
ll n,Ti=0,k=0,s,mid,l,r,a[100005],temp,idx[100005];
bool cmp(ll b,ll c){
    return (a[b]+b*mid<a[c]+c*mid);
}
bool check(ll mid){
    temp=0;
    for(int i=1;i<=n;i++) idx[i]=i;
    sort(idx+1,idx+1+n,cmp);
    for(int i=1;i<=mid;i++){
        temp+=a[idx[i]]+idx[i]*mid;
        //cout<<a[idx[i]]<<" "<<idx[i]<<endl;
    }
    if(temp<=s){
        if(mid>k){
            k=mid;
            Ti=temp;
        }
        return 1;
    }
    else return 0;
}
int main(){
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    l=1,r=n;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    cout<<k<<" "<<Ti<<endl;
	return 0;
}
