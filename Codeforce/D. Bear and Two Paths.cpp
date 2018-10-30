#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int a,b,c,d,n,m,idx=1,i;
vector<int> ans1,ans2;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>a>>b>>c>>d;
	if(n==4||m<n+1){
        cout<<-1<<endl;
        return 0;
	}
	ans1.resize(n),ans2.resize(n);
	ans1[0]=a,ans1[1]=c,ans1[n-1]=b,ans1[n-2]=d;
	i=2;
	while(idx<=n){
        if(idx==a||idx==b||idx==c||idx==d) idx++;
        else ans1[i++]=idx++;
	}
	ans2[0]=c,ans2[1]=a;
	for(int i=2;i<ans1.size();i++) ans2[i]=ans1[i];
	swap(ans2[n-1],ans2[n-2]);
	for(int i=0;i<n;i++) cout<<ans1[i]<<" ";
	cout<<endl;
	for(int i=0;i<n;i++) cout<<ans2[i]<<" ";
	return 0;
}
