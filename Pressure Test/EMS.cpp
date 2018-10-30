#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define F first
#define S second
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
pii pos[1005];
int n,Ti=0,dsu[1005];
vector<piii> edge;
int findDSU(int x){
    if(x==dsu[x]) return x;
    else return dsu[x]=findDSU(dsu[x]);
}
void mergeDSU(int a,int b){
    a=findDSU(a);
    b=findDSU(b);
    if(a==b) return;
    dsu[a]=b;
}
int calSquare(pii a,pii b){
    return (a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S);
}
int main(){
	ios_base::sync_with_stdio(0);
	fr("EMS.INP");
	fw("EMS.OUT");
    cin>>n;
    for(int i=1;i<=n;i++) cin>>pos[i].F>>pos[i].S,dsu[i]=i;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            edge.push_back({calSquare(pos[i],pos[j]),{i,j}});
        }
    }
    sort(edge.begin(),edge.end());
    for(auto temp:edge){
        if(findDSU(temp.S.F)!=findDSU(temp.S.S)){
            Ti=max(Ti,temp.F);
            mergeDSU(temp.S.F,temp.S.S);
        }
    }
    cout<<Ti<<endl;
	return 0;
}
