#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
int times[100]={0},n,Ti=90;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>times[i];
	for(int i=1;i<=n;i++){
        if(times[i]-times[i-1]>15){
            Ti=times[i-1]+15;
            break;
        }
        if(i==n){
            if(90-times[i]>15) Ti=times[i]+15;
        }
	}
	cout<<Ti<<endl;
	return 0;
}
