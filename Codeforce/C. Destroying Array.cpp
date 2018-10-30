#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define M 100005
using namespace std;
typedef long long int ll;
ll sum[M]={0},dsu[M],p[M],a[M],n,Ti[M],curMax=0,temp;
bool avai[M]={0};
ll finddsu(ll u){
    if(dsu[u]==u) return u;
    else return dsu[u]=finddsu(dsu[u]);
}
void uniondsu(ll u,ll v){
    u=finddsu(u);
    v=finddsu(v);
    if(u!=v){
        dsu[v]=u;
        sum[u]+=sum[v];
        sum[v]=0;
        curMax=max(curMax,sum[u]);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>p[i],dsu[i]=i;
    dsu[0]=0,dsu[n+1]=n+1;
    for(int i=n;i>=1;i--){
        Ti[i]=curMax;
        avai[p[i]]=1;
        sum[p[i]]=a[p[i]];
        curMax=max(curMax,sum[p[i]]);
        temp=finddsu(p[i]);
        if(avai[temp+1]) uniondsu(temp,temp+1);
        temp=finddsu(p[i]);
        if(avai[temp-1]) uniondsu(temp,temp-1);
    }
    for(int i=1;i<=n;i++) cout<<Ti[i]<<endl;
	return 0;
}
