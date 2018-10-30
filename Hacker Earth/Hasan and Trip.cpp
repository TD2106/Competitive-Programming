#include <iostream>
#include <cmath>
using namespace std;
int main (){
	int n;
	double data[4][3005]={0.0},maxsum=0,x,y;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>data[0][i]>>data[1][i]>>data[2][i];
		data[3][i]=data[2][i];
	}
	for(int i=2;i<n;i++){
		for(int j=i-1;j>1;j--){
			data[3][i]=max(data[3][i],data[2][i]+data[3][j]-sqrt(pow(abs(data[0][i]-data[0][j]),2)+pow(abs(data[1][i]-data[1][j]),2)));
		}
		maxsum=max(maxsum,data[1][2]+data[n][2]+data[3][i]
	}
	cout<<data[3][n];
	return 0;
}
