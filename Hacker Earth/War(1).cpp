#include <iostream>
#include <algorithm>
using namespace std;
int main (){
	int n,bob,alice,temp,tc;
	cin>>tc;
	while(tc--){
		cin>>n;
		bob=alice=-1;
		for(int i=0;i<n;i++){
			cin>>temp;
			bob=max(bob,temp);
		}
		for(int i=0;i<n;i++){
			cin>>temp;
			alice=max(alice,temp);
		}
		if(alice==bob) cout<<"Tie\n";
		else if(alice>bob) cout<<"Alice\n";
		else cout<<"Bob\n";
	}
	return 0;
}
