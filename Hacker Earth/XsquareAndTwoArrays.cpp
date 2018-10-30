#include <iostream>
using namespace std;
long long A[100010]={0},B[100010]={0},n,q,sum[2][100010]={0},com,L,R;
int main (){
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>A[i];
	for(int i=1;i<=n;i++) cin>>B[i];
	for(int i=1;i<=n;i++){
		if(i%2) sum[0][i]+=sum[0][i-1]+A[i],sum[1][i]+=sum[1][i-1]+B[i];
		else sum[0][i]+=sum[0][i-1]+B[i],sum[1][i]+=sum[1][i-1]+A[i];
	}
	while(q--){
		cin>>com>>L>>R;
		if(com%2){
			if(L%2) cout<<sum[0][R]-sum[0][L-1]<<endl;
			else cout<<sum[1][R]-sum[1][L-1]<<endl;
		}
		else{
			if(L%2==0) cout<<sum[0][R]-sum[0][L-1]<<endl;
			else cout<<sum[1][R]-sum[1][L-1]<<endl;
		}
	}
	return 0;
}
