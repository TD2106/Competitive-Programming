#include <bits/stdc++.h>
#define bug(x) cout << #x << " = " << x << endl
using namespace std;
typedef long long int ll;
double n,a,angle,mn,minRes=1e9;
int Ti;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>a;
	angle=(n-2)*180/n;
	mn=180/n;
	for(int i=3;i<=n;i++){
        if(abs(angle-(i-3)*mn-a)<minRes){
            minRes=abs(angle-(i-3)*mn-a);
            Ti=i;
        }
	}
	cout<<1<<" "<<2<<" "<<Ti<<endl;
	return 0;
}
