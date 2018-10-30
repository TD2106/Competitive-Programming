#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;
pair<int,int> a[1000001],p[1000001];
int n,q,np,b,e,j,c[1000001],d[1000001];
int main (){
	freopen("uniquek.txt","r",stdin);
	cin>>n>>q;
	while(n>0){
		memset(p,0,sizeof(p));np=0;
		memset(d,0,sizeof(d));
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		for(int i=0;i<n;i++){
			cin>>d[i];
			a[i].first=d[i];
			a[i].second=i;
		}
		sort(a,a+n);
		for(int i=0;i<n;i++){
			cout<<a[i].first<<" "<<a[i].second<<endl;
		}
		cout<<endl;
		for(int i=1;i<n;i++){
			if(a[i].first==a[i-1].first){
				p[++np].first=a[i].second;
				p[np].second=a[i-1].second;
			}
		}
		sort(p+1,p+1+np,greater< pair<int,int> >());
		for(int i=1;i<=np;i++){
			cout<<p[i].first<<" "<<p[i].second<<endl;
		}
		cout<<endl;
		for(int i=np;i>=1;i--){
			j=p[i].second;
			c[j]=p[i].first;
		}
		c[n]=n;
		for(int i=n-1;i>=0;i--){
			if(c[i]==0||c[i]>c[i+1])
			c[i]=c[i+1];
		}
		for(int i=0;i<=n;i++)
		cout<<c[i]<<endl;
		cout<<endl;
		while(q--){
			cin>>b>>e;
			b--;
			e--;
			if(e<c[b]) cout<<"OK\n";
			else cout<<d[c[b]]<<"\n";
		}
		cin>>n>>q;
	}
	return 0;
}
