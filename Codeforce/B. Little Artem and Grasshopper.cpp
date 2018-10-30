#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
using namespace std;
typedef long long int ll;
int n,cur=1;
pair<char,int> cell[100005];
bool Ti[100005]={0};
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>cell[i].first;
	for(int i=1;i<=n;i++) cin>>cell[i].second;
	while((cur>=1&&cur<=n)&&Ti[cur]==0){
        Ti[cur]=1;
        if(cell[cur].first=='>') cur+=cell[cur].second;
        else cur-=cell[cur].second;
	}
	if((cur>=1&&cur<=n)) cout<<"INFINITE";
	else cout<<"FINITE";
	return 0;
}
