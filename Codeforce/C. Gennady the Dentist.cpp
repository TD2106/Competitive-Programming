#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
struct child{
    ll v,d,p;
}c[4005];
ll n,temp,td;
vector<ll> Ti;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>c[i].v>>c[i].d>>c[i].p;
	for(int i=1;i<=n;i++){
        if(c[i].p>=0){
            Ti.push_back(i);
            temp=c[i].v;
            td=0;
            for(int j=i+1;j<=n;j++,temp--){
                if(c[j].p<0){
                     temp++;
                     continue;
                }
                if(temp>=0) c[j].p-=(temp+td);
                else c[j].p-=td;
                if(c[j].p<0) td+=c[j].d;
            }
        }
	}
	cout<<Ti.size()<<endl;
	for(int i=0;i<Ti.size();i++) cout<<Ti[i]<<" ";
	return 0;
}
