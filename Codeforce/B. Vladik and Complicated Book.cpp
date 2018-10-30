#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define reset(x) memset(x,0,sizeof(x))
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
int n,m,cnt[10005]={0},p[10005],l,r,x,t,c=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>p[i];
    while(m--){
        cin>>l>>r>>x;
        t=p[x];
        c=0;
        for(int i=l;i<=r;i++){
            if(p[i]<t) c++;
        }
        if(c==x-l) cout<<"Yes\n";
        else cout<<"No\n";
    }
	return 0;
}
