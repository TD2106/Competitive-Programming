#include <bits/stdc++.h>
#define reset(a) memset(a,0,sizeof(a))
#define M 200005
#define bug(x) cout << #x << " = " << x << endl;
using namespace std;
bool mark[M];
string t,p;
int l,r,Ti=0,a[M],mid;
bool check(int m){
    int idxt,idxp;
    idxt=idxp=0;
    reset(mark);
    for(int i=0;i<m;i++) mark[a[i]]=1;
        //cout<<a[i]<<endl;
    while(idxt<t.size()&&idxp<p.size()){
        if(t[idxt]==p[idxp]&&!mark[idxt]) idxt++,idxp++;
        else idxt++;
    }
    if(idxp==p.size()) return 1;
    else return 0;
}
int main(){
    cin>>t>>p;
    for(int i=0;i<t.size();i++) cin>>a[i],a[i]--;
    l=0,r=t.size();
    while(l<=r){
        //cout<<l<<" "<<r<<endl;
        mid=(l+r)/2;
        if(check(mid)) l=mid+1,Ti=max(Ti,mid);
        else r=mid-1;
    }
    //cout<<check(4)<<endl;
    cout<<Ti<<endl;
    return 0;
}



