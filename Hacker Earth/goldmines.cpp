#include <iostream>
using namespace std;
typedef long long ll;
ll sum[1010][1010]={0};
int main (){
	ll n,m,q,x1,x2,y1,y2,temp;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>temp;
			sum[i][j]=temp+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		}
	}
	cin>>q;
	while(q--){
		cin>>x1>>y1>>x2>>y2;
		cout<<sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]<<endl;
	}
	return 0;
}
