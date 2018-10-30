#include <iostream>
#include <bitset>
using namespace std;
int main () {
	bitset<10001> city;
	int tc,a,b,n,cnt;
	cin>>tc;
	while(tc--){
		cnt=0;
		city.reset();
		cin>>n;
		while(n--){
			cin>>a>>b;
			if(!city[a]){
				cnt++;
				city[a]=1;
			}
			if(!city[b]){
				cnt++;
				city[b]=1;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
